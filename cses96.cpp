#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> ans;

bool dfs(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& path) {
    visited[node] = true;
    path[node] = true;

    for (auto it : adj[node]) {
        if (!visited[it]) {
            parent[it] = node;
            if (dfs(it, adj, visited, path)) {
                return true;
            }
        }
        else if (path[it]) {  
            int cur = node;
            ans.push_back(it);
            while (cur != it) {
                ans.push_back(cur);
                cur = parent[cur];
            }
            ans.push_back(it); 
            reverse(ans.begin(), ans.end());
            return true;
        }
    }

    path[node] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    parent.assign(n+1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);  
    }

    vector<bool> visited(n+1, false);
    vector<bool> path(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, path)) {
                cout << ans.size() << "\n";
                for (int x : ans) cout << x << " ";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
