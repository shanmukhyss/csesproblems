#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
vector<long long> dp;
vector<int> coins;

long long solve(int sum) {
    if (sum == 0) return 1;
    if (sum < 0) return 0;

    if (dp[sum] != -1)
        return dp[sum];

    long long ways = 0;
    for (int c : coins) {
        ways = (ways + solve(sum - c)) % MOD;
    }

    return dp[sum] = ways;
}

int main() {
    int n, x;
    cin >> n >> x;

    coins.resize(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    dp.assign(x + 1, -1);

    cout << solve(x) << endl;
    return 0;
}
