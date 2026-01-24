#include<bits/stdc++.h>
using namespace std;
int ans=0;
vector<bool>matched;
void dfs( int node, int parent ,vector<int>adj[]){
    for(auto it:adj[node]){
        if(it==parent){
            continue;
        }
        dfs(it,node,adj);
    }
    if(parent!=-1 && !matched[node] && !matched[parent]){
        ans++;
        matched[node]=true;
        matched[parent]=true;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    matched.resize(n+1,false);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1,adj);
    cout<<ans<<endl;
    return 0;
   
   
}