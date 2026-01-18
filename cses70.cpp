#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long>a(n);
    vector<long long>b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[n][m]<<endl;
      int i = n, j = m;
    vector<long long> lcs;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i][j - 1] > dp[i - 1][j]) {
            j--;
        } else {
            i--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    for(int i=0;i<lcs.size();i++){
        cout<<lcs[i]<<" ";
    }
    return 0;

}