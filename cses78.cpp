#include<bits/stdc++.h>
using namespace std;
bool compare(vector<long long>&a, vector<long long>&b){
    return a[1]<b[1];
}
int main(){
    int n;
    cin>>n;
    vector<vector<long long>>v(n,vector<long long>(3));
    for(int i=0;i<n;i++){
        cin>>v[i][0];
        cin>>v[i][1];
        cin>>v[i][2];
    }
    sort(v.begin(),v.end(),compare);
    vector<long long>ends;

    vector<long long>dp(n+1,0);
  
    for(int i=0;i<n;i++){
        long long take=v[i][2];
        auto j= upper_bound(ends.begin(),ends.end(),v[i][0]-1)-ends.begin()-1;
        if(j>=0){
           take+=dp[j];
        }
        long long nottake= i>=1?dp[i-1]:0;
        dp[i]=max(take,nottake);
          ends.push_back(v[i][1]);
    }  
    
    cout<<dp[n-1]<<endl;
    return 0;

}