#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
vector<vector<int>>dp;
int solve(int ind, int sum, vector<int>&v){
    if(sum==0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    if(ind>=v.size()){
        return 0;
    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    int take=solve(ind+1,sum-v[ind],v);
    int nottake=solve(ind+1,sum,v);
    return dp[ind][sum]=(take+nottake)%mod;
}
int main(){
    int n;
    cin>>n;
    int total=0;
    vector<int>v(n+1,0);
    for(int i=1;i<=n;i++){
        total+=i;
        v[i]=i;
    }
    dp.assign(n+2,vector<int>(total+1,-1));
    if(total%2!=0){
        cout<<0<<endl;
        return 0;
    }
    else{
       long long ans = (1LL * solve(1, total/2, v) * 500000004) % mod;

        cout<<ans%mod<<endl;
        return 0;
    }

}