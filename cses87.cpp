#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>teams;
bool dfs(int i, vector<int> adj[], vector<bool>&visited, bool grp1){
    visited[i]=true;
    if(grp1){
        teams[i]=1;
    }
    else{
        teams[i]=2;
    }
    for(auto it:adj[i]){
        if(!visited[it]){
            if(!dfs(it, adj, visited, !grp1)){
                return false;
            }
        }
        else if(teams[it]==teams[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    teams.assign(n+1,-1);
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(!dfs(i,adj,visited,true)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<teams[i]<<" ";
    }
    return 0;
}