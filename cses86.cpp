#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int>q;
    q.push(1);
    vector<int>dist(n+1,1e9);
    vector<int>visited(n+1,-1);
    vector<int>parent(n+1,0);
    vector<int>ans;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    dist[1]=0;
    visited[1]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x==n){
            break;
        }
        for(auto it:adj[x]){
            if( dist[x]+1<dist[it] && visited[it]==-1){
                visited[it]=1;
                dist[it]=1+dist[x];
                parent[it]=x;
                q.push(it);
            }
        }
    }
    if(dist[n]==1e9){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dist[n]+1<<endl;
        int ind=n;
        while(parent[ind]!=ind){
            ans.push_back(ind);
            ind=parent[ind];
        }
        ans.push_back(ind);
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}