#include<bits/stdc++.h>
using namespace std;
vector<bool>visited;
vector<int>ids;
stack<int>st;
void dfs(int node, vector<int>adj[]){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
        dfs(it,adj);
        }
    }
    st.push(node);
}
void dfs2(int node, vector<int>adj[], int k){
    visited[node]=true;
    ids[node]=k;
    for(auto it:adj[node]){
       if(!visited[it]){
        dfs2(it,adj,k);
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
    visited.assign(n+1,false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
           dfs(i, adj);
        }
    }


    visited.assign(n+1,false);
    ids.assign(n+1,0);

    int count=0;
    int id=1;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            count++;
            dfs2(node,radj,id);
            id++;
        }
    }
    cout<<count<<endl;

    for(int i=1;i<=n;i++){
        cout<<ids[i]<<" ";
    }
    return 0;

}