#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m;
vector<long long>dp;
long long dfs(int node, vector<int>adj[],vector<bool>&visited){
    if(node==n){
        return 1;
    }
    if(dp[node]!=-1){
        return dp[node];
    }
    long long ans=0;
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            ans=(ans+dfs(it,adj,visited))%mod;
        }
    }
    visited[node]=false;
    return dp[node]=ans;
}
int main(){
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
       int a,b;
       cin>>a>>b;
       adj[a].push_back(b);
    }
    dp.assign(n+1,-1);
    vector<bool>visited(n+1,false);
  cout<<dfs(1,adj,visited)<<endl;
}