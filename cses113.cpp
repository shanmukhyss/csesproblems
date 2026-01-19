#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    int FULL = 1 << n;
    vector<vector<int>> dp(FULL, vector<int>(n, 0));

    dp[1][0] = 1;  
    for (int mask = 1; mask < FULL; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] == 0) continue;
            for (int v : adj[u]) {
                if (mask & (1 << v)) continue;
                int newmask = mask | (1 << v);
                dp[newmask][v] = (dp[newmask][v] + dp[mask][u]) % mod;
            }
        }
    }
    cout << dp[FULL - 1][n - 1] << endl;
    return 0;
}
