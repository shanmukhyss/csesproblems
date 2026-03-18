#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin >> coin[i];

    vector<vector<int>> dp(n+1, vector<int>(x + 1, 0));

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int target = 1; target <= x; target++)
        dp[n][target] = 0;

    for(int ind = n - 1; ind >= 0; ind--){
        for(int target = 0; target <= x; target++){
            dp[ind][target] = dp[ind + 1][target];

            if(coin[ind] <= target){
                dp[ind][target] = (dp[ind][target] +
                                  dp[ind][target - coin[ind]]) % mod;
            }
        }
    }

    cout << dp[0][x] << endl;
}