#include<bits/stdc++.h>
using namespace std;

const int LOG = 19;

vector<vector<int>> up;
vector<int> depth;
vector<vector<int>> adj;

void dfs(int node, int parent) {
    for (auto it : adj[node]) {
        if (it == parent) continue;
        depth[it] = depth[node] + 1;   
        dfs(it, node);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {   
        swap(a, b);
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != -1 && depth[up[a][i]] >= depth[b]) { 
            a = up[a][i];
        }
    }

    if (a == b) return b;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != -1 && up[b][i] != -1 && up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[b][0];  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    up.assign(n + 1, vector<int>(LOG, -1));  
    depth.assign(n + 1, 0);
    adj.assign(n + 1, vector<int>());

    vector<int> parent(n + 1);
    parent[1] = -1;

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        parent[i] = boss;
        adj[i].push_back(boss);
        adj[boss].push_back(i);
        up[i][0] = boss;
    }

    dfs(1, -1);

    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            int mid = up[i][k - 1];
            if (mid != -1) {
                up[i][k] = up[mid][k - 1];
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}
