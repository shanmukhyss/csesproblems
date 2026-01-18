#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
vector<bool>visited;
stack<int>st;
void dfs(int node, vector<pair<int,int>>adj[]){
    while(!adj[node].empty()){
        auto [v,id]=adj[node].back();
        adj[node].pop_back();
        if(visited[id]){
            continue;
        }
        visited[id]=true;
        dfs(v,adj);
    }
    st.push(node);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    vector<int>degree(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
        degree[a]++;
        degree[b]++;
    }

    for(int i=1;i<=n;i++){
        if(degree[i]%2!=0){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    
    visited.assign(m,false);
    dfs(1, adj);
 
    vector<int>ans;
    int count=0;
    while(!st.empty()){
        int t=st.top();
        st.pop();
        ans.push_back(t); 
        count++;  
    }
    if(count!=m+1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
   
}