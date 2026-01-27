#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, k1, k2;
vector<int> adj[MAXN];
int sz[MAXN];
bool removed[MAXN];
int cnt[MAXN];          // frequency of distances
long long answer = 0;

/* compute subtree sizes */
void dfs_size(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
    }
}

/* find centroid */
int dfs_centroid(int u, int p, int total) {
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        if (sz[v] > total / 2)
            return dfs_centroid(v, u, total);
    }
    return u;
}

/* collect distances */
void dfs_dist(int u, int p, int d, vector<int> &dist) {
    if (d > k2) return;
    dist.push_back(d);
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        dfs_dist(v, u, d + 1, dist);
    }
}

/* centroid decomposition */
void decompose(int entry) {
    dfs_size(entry, -1);
    int c = dfs_centroid(entry, -1, sz[entry]);
    removed[c] = true;

    vector<int> used;
    cnt[0] = 1;
    used.push_back(0);

    for (int v : adj[c]) {
        if (removed[v]) continue;

        vector<int> dist;
        dfs_dist(v, c, 1, dist);

        /* count valid paths */
        for (int d : dist) {
            int L = max(0, k1 - d);
            int R = k2 - d;
            if (L > R) continue;

            for (int x = L; x <= R; x++)
                answer += cnt[x];
        }

        /* update counts */
        for (int d : dist) {
            if (cnt[d] == 0)
                used.push_back(d);
            cnt[d]++;
        }
    }

    /* cleanup */
    for (int x : used)
        cnt[x] = 0;

    for (int v : adj[c]) {
        if (!removed[v])
            decompose(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k1 >> k2;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    decompose(1);
    cout << answer << '\n';
    return 0;
}
