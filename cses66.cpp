#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    vector<int>pages(n);
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }

    vector<int>dp(x+1,0);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=x;j>=0;j--){
            int nottake=dp[j];
            int take=0;
            if(j>=prices[i]){
                take=pages[i]+dp[j-prices[i]];
            }
            dp[j]=max(take,nottake);
        }
    }
   cout<<dp[x]<<endl;
   return 0;
}