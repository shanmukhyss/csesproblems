#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, k;
vector<int> adj[MAXN];
int sz[MAXN];
bool removed[MAXN];
int cnt[MAXN];
long long answer = 0;

/* subtree sizes */
void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

/* centroid */
int centroid(int u, int p, int size) {
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        if (sz[v] > size / 2)
            return centroid(v, u, size);
    }
    return u;
}

/* collect distances */
void get_dist(int u, int p, int d, vector<int> &dist) {
    if (d > k) return;
    dist.push_back(d);
    for (int v : adj[u]) {
        if (v == p || removed[v]) continue;
        get_dist(v, u, d + 1, dist);
    }
}

/* centroid decomposition */
void decompose(int entry) {
    dfs(entry, -1);
    int c = centroid(entry, -1, sz[entry]);
    removed[c] = true;

    vector<int> used;
    cnt[0] = 1;
    used.push_back(0);

    for (int v : adj[c]) {
        if (removed[v]) continue;

        vector<int> dist;
        get_dist(v, c, 1, dist);

        for (int d : dist) {
            if (k - d >= 0)
                answer += cnt[k - d];
        }

        for (int d : dist) {
            if (cnt[d] == 0) used.push_back(d);
            cnt[d]++;
        }
    }

    // cleanup
    for (int d : used) cnt[d] = 0;

    for (int v : adj[c]) {
        if (!removed[v])
            decompose(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    decompose(1);
    cout << answer << '\n';
}
