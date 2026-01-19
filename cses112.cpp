#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void dfs(int node, vector<int> adj[]) {
    while (!adj[node].empty()) {
        int nxt = adj[node].back();
        adj[node].pop_back();
        dfs(nxt, adj);
    }
    ans.push_back(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    vector<int> indeg(n+1, 0), outdeg(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        outdeg[a]++;
        indeg[b]++;
    }

    // Degree check
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (outdeg[i] - indeg[i] != 1) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        } else if (i == n) {
            if (indeg[i] - outdeg[i] != 1) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        } else {
            if (indeg[i] != outdeg[i]) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    dfs(1, adj);
    reverse(ans.begin(), ans.end());

    if (ans.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int x : ans) cout << x << " ";
}
