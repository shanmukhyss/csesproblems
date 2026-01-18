#include<bits/stdc++.h>
using namespace std;
vector<long long> dp;
long long  func(vector<long long>&v ,long long sum){
    if(dp[sum]!=-1){
        return dp[sum];
    }
    if(sum==0){
        return dp[sum]=0;
    }
    if(sum<0){
        return LONG_LONG_MAX;
    }

    long long ans=LONG_LONG_MAX;
    for(auto c:v){
        if(c<=sum){
            long long sub=func(v,sum-c);
            if(sub!=LONG_LONG_MAX){
                ans=min(ans,1+sub);
            }
        }
    }
    return dp[sum]=ans;
}
int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    dp.assign(x+1,-1);
    long long ans=func(v,x);

    if(ans!=LONG_LONG_MAX){
    cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}