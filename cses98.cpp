#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indeg[i] == 0)
            q.push(i);

    vector<int> dp(n + 1, -1e9), parent(n + 1, -1);
    dp[1] = 1;   // number of nodes in path

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
            if(--indeg[v] == 0)
                q.push(v);
        }
    }

    if(dp[n] < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dp[n] << "\n";

    vector<int> path;
    for(int cur = n; cur != -1; cur = parent[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());
    for(int x : path)
        cout << x << " ";
    cout << "\n";

    return 0;
}
