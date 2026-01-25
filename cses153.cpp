#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> adj[200005];
vector<long long> val;
vector<int> tin, sz;
vector<long long> fenwick;
int timer = 0;

/* Fenwick Tree */
void update(int i, long long delta) {
    while (i <= n) {
        fenwick[i] += delta;
        i += i & -i;
    }
}

long long query(int i) {
    long long s = 0;
    while (i > 0) {
        s += fenwick[i];
        i -= i & -i;
    }
    return s;
}

long long range_query(int l, int r) {
    return query(r) - query(l - 1);
}

/* DFS to flatten tree */
void dfs(int u, int p) {
    tin[u] = ++timer;
    sz[u] = 1;

    update(tin[u], val[u]);  // initial value

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    val.assign(n + 1, 0);
    tin.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    fenwick.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Root the tree at 1
    dfs(1, 0);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            long long x;
            cin >> s >> x;
            long long diff = x - val[s];
            val[s] = x;
            update(tin[s], diff);
        } else {
            int s;
            cin >> s;
            cout << range_query(tin[s], tin[s] + sz[s] - 1) << '\n';
        }
    }

    return 0;
}
