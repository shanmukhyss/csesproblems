#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;

int n;
vector<int> adj[MAXN + 1];
long long dp[MAXN + 1], ans[MAXN + 1];
int sub[MAXN + 1];

void dfs1(int v, int parent) {
    sub[v] = 1;
    dp[v] = 0;

    for (int u : adj[v]) {
        if (u == parent) continue;
        dfs1(u, v);
        sub[v] += sub[u];
        dp[v] += dp[u] + sub[u];
    }
}

void dfs2(int v, int parent) {
    for (int u : adj[v]) {
        if (u == parent) continue;

        ans[u] = ans[v] - sub[u] + (n - sub[u]);
        dfs2(u, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0);
    ans[1] = dp[1];
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
