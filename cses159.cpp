#include <bits/stdc++.h>
using namespace std;

class fenwick {
public:
    int n;
    vector<int> bit;
    fenwick(int n = 0) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void reset(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int i, int v) { 
        while (i <= n) {
            bit[i] += v;
            i += i & -i;
        }
    }
    int sum(int i) { 
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    int range(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

const int MAXN = 200000 + 5;

int n, k1, k2;
vector<int> adj[MAXN];
int sz[MAXN];
bool removed[MAXN];
int cnt[MAXN];
long long answer = 0;


void dfs(int node, int parent) {
    sz[node] = 1;
    for (auto it : adj[node]) {
        if (it == parent || removed[it]) continue;
        dfs(it, node);
        sz[node] += sz[it];
    }
}


int get_centroid(int node, int parent, int total) {
    for (auto it : adj[node]) {
        if (it == parent || removed[it]) continue;
        if (sz[it] > total / 2)
            return get_centroid(it, node, total);
    }
    return node;
}

void get_depths(int node, int parent, int depth, vector<int>& depths) {
    if (depth > k2) return;
    depths.push_back(depth);
    for (auto it : adj[node]) {
        if (it == parent || removed[it]) continue;
        get_depths(it, node, depth + 1, depths);
    }
}

void decompose(int node) {
    dfs(node, -1);
    int c = get_centroid(node, -1, sz[node]);
    removed[c] = true;

    vector<vector<int>> allDepths;
    int maxDepth = 0;

    for (auto it : adj[c]) {
        if (removed[it]) continue;
        vector<int> depths;
        get_depths(it, c, 1, depths);
        for (int d : depths) maxDepth = max(maxDepth, d);
        if (!depths.empty())
            allDepths.push_back(depths);
    }

    maxDepth = min(maxDepth, k2);

    fenwick fw(maxDepth + 2);
    vector<int> used;
    fw.add(1, 1);  
    cnt[0] = 1;
    used.push_back(0);

    for (auto &depths : allDepths) {
        for (int d : depths) {
            int L = max(0, k1 - d);
            int R = min(maxDepth, k2 - d);
            if (L <= R)
                answer += fw.range(L + 1, R + 1);
        }
        for (int d : depths) {
            if (cnt[d] == 0) used.push_back(d);
            cnt[d]++;
            fw.add(d + 1, 1);
        }
    }
    for (int d : used)
        cnt[d] = 0;

    for (auto it : adj[c])
        if (!removed[it])
            decompose(it);
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
