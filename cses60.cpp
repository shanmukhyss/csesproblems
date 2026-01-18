#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
vector<long long> dp;

long long func(int sum) {
    if (sum < 0) return 0;
    if (sum == 0) return 1;

    if (dp[sum] != -1) return dp[sum];

    long long ways = 0;
    for (int i = 1; i <= 6; i++) {
        ways = (ways + func(sum - i)) % mod;
    }

    return dp[sum] = ways;
}

int main() {
    int n;
    cin >> n;

    dp.assign(n + 1, -1);
    cout << func(n) << endl;
    return 0;
}
