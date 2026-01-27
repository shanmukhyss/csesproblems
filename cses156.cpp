#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200005;

vector<int> adj[MAXN];
int color[MAXN];
int sz[MAXN], heavy[MAXN];
int ans[MAXN];

int freq[MAXN];
int distinctColors = 0;

void dfs_sz(int u, int p) {
    sz[u] = 1;
    int mx = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if (sz[v] > mx) {
            mx = sz[v];
            heavy[u] = v;
        }
    }
}

void add_subtree(int u, int p, int delta) {
    if (delta == 1) {
        if (freq[color[u]]++ == 0)
            distinctColors++;
    } else {
        if (--freq[color[u]] == 0)
            distinctColors--;
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        add_subtree(v, u, delta);
    }
}

void dfs(int u, int p, bool keep) {
    // process light children
    for (int v : adj[u]) {
        if (v == p || v == heavy[u]) continue;
        dfs(v, u, false);
    }

    // process heavy child
    if (heavy[u])
        dfs(heavy[u], u, true);

    // add light subtrees
    for (int v : adj[u]) {
        if (v == p || v == heavy[u]) continue;
        add_subtree(v, u, 1);
    }

    // add current node
    if (freq[color[u]]++ == 0)
        distinctColors++;

    ans[u] = distinctColors;
    if (!keep) {
        add_subtree(u, p, -1);
        distinctColors = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> colors_input(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> colors_input[i];

    // Compress colors
    vector<int> sorted_colors;
    for (int i = 1; i <= n; i++)
        sorted_colors.push_back(colors_input[i]);
    
    sort(sorted_colors.begin(), sorted_colors.end());
    sorted_colors.erase(unique(sorted_colors.begin(), sorted_colors.end()), sorted_colors.end());
    
    map<int, int> compress;
    for (int i = 0; i < sorted_colors.size(); i++)
        compress[sorted_colors[i]] = i + 1;
    
    for (int i = 1; i <= n; i++)
        color[i] = compress[colors_input[i]];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_sz(1, 0);
    dfs(1, 0, true);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    cout << '\n';
    return 0;
}