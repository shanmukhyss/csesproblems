#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin >> coin[i];

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    // Base case
    for(int i = 0; i < n; i++)
        dp[i][0] = 1;

     for(int i=0;i<=x;i++){
        if(i%coin[0]==0){
            dp[0][i]=1;
        }
     }
        
   for(int i=1;i<n;i++){
      for(int sum=1;sum<=x;sum++){
        int nottake=dp[i-1][sum];
        int take=0;
        if(sum>=coin[i]){
            take=dp[i][sum-coin[i]];
        }
        dp[i][sum]=(take+nottake)%mod;
      }
   }

    cout << dp[n-1][x] << endl;
}
