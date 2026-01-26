#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];
int parent[N], depth[N], heavy[N], head[N], pos[N];
int sz[N];
int cur_pos;
long long val[N];
long long seg[4*N];

void dfs(int u, int p) {
    parent[u] = p;
    sz[u] = 1;
    int maxsz = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > maxsz) {
            maxsz = sz[v];
            heavy[u] = v;
        }
    }
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = ++cur_pos;

    if (heavy[u]) {
        decompose(heavy[u], h);
    }

    for (int v : adj[u]) {
        if (v == parent[u] || v == heavy[u]) continue;
        decompose(v, v);
    }
}

/* Segment Tree */
void update(int idx, long long v, int node, int l, int r) {
    if (l == r) {
        seg[node] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(idx, v, node*2, l, mid);
    else update(idx, v, node*2+1, mid+1, r);
    seg[node] = max(seg[node*2], seg[node*2+1]);
}

long long query(int ql, int qr, int node, int l, int r) {
    if (qr < l || r < ql) return LLONG_MIN;
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    return max(query(ql, qr, node*2, l, mid),
               query(ql, qr, node*2+1, mid+1, r));
}

long long path_query(int a, int b, int n) {
    long long res = LLONG_MIN;

    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]])
            swap(a, b);
        res = max(res, query(pos[head[a]], pos[a], 1, 1, n));
        a = parent[head[a]];
    }

    if (depth[a] > depth[b]) swap(a, b);
    res = max(res, query(pos[a], pos[b], 1, 1, n));

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    decompose(1, 1);

    for (int i = 1; i <= n; i++) {
        update(pos[i], val[i], 1, 1, n);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            long long x;
            cin >> s >> x;
            val[s] = x;
            update(pos[s], x, 1, 1, n);
        } else {
            int a, b;
            cin >> a >> b;
            cout << path_query(a, b, n) << '\n';
        }
    }

    return 0;
}
