#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int>adj[],vector<bool>&visited, vector<bool>&path){
    visited[node]=true;
    path[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(it,adj,visited,path)){
                return true;
            }
        }
        else if(path[it]){
            return true;
        }
    }
    path[node]=false;
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int> indegree(n+1, 0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    vector<bool>visited(n+1,false);
    vector<bool>path(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,path)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }

    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
 
}