#include<bits/stdc++.h>
using namespace std;

stack<int> st;
vector<bool> visited;
vector<int> ids;
vector<long long> sums;

void dfs(int node, vector<int> adj[]) {
    visited[node] = true;
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, adj);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> radj[], int k, long long &sum, vector<int>& coins) {
    visited[node] = true;
    ids[node] = k;
    sum += coins[node];
    for (auto it : radj[node]) {
        if (!visited[it]) {
            dfs2(it, radj, k, sum, coins);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1], radj[n+1];
    vector<int> coins(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    visited.assign(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj);
        }
    }

    visited.assign(n+1, false);
    ids.assign(n+1, 0);

    int id = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            long long sum = 0;
            dfs2(node, radj, id, sum, coins);
            sums.push_back(sum);
            id++;
        }
    }

    vector<vector<int>> dag(id);
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (ids[u] != ids[v]) {
                dag[ids[u]].push_back(ids[v]);
            }
        }
    }

    vector<long long> dp(id);
    for (int i = 0; i < id; i++) {
        dp[i] = sums[i];
    }

    for (int i = 0; i < id; i++) {
        for (auto j : dag[i]) {
            dp[j] = max(dp[j], dp[i] + sums[j]);
        }
    }

    long long ans = 0;
    for (int i = 0; i < id; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}
