#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>adj[], vector<bool>&visited){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>radj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vector<bool>visited(n+1,false);
    dfs(1,adj,visited);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    visited.assign(n+1,false);
    dfs(1,radj,visited);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    return 0;
}