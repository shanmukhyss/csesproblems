#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n, m;
vector<int> v;
vector<vector<int>> dp;

int solve(int i, int prev) {
    if (i == n) return 1;

    if (dp[i][prev] != -1) return dp[i][prev];

    long long ans = 0;

    if (v[i] != 0) {
        if (abs(v[i] - prev) <= 1) {
            ans = solve(i + 1, v[i]);
        }
    } else {
        // Only 3 possible choices
        for (int x = prev - 1; x <= prev + 1; x++) {
            if (x >= 1 && x <= m) {
                ans = (ans + solve(i + 1, x)) % mod;
            }
        }
    }

    return dp[i][prev] = ans;
}

int main() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    dp.assign(n, vector<int>(m + 1, -1));

    long long ans = 0;

    // Handle first index separately
    if (v[0] == 0) {
        for (int x = 1; x <= m; x++) {
            ans = (ans + solve(1, x)) % mod;
        }
    } else {
        ans = solve(1, v[0]);
    }

    cout << ans << endl;
    return 0;
}
