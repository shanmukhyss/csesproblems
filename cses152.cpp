#include<bits/stdc++.h>
using namespace std;
vector<int>depth;
vector<vector<int>>up;
vector<int>cnt;
void dfs( int node, int parent, vector<int>adj[]){
    up[node][0]=parent;
    for( auto it:adj[node]){
        if(it==parent){
            continue;
        }
        depth[it]=depth[node]+1;
        dfs(it,node,adj);
    }
}
int lca( int a,int b){
    if(depth[b]>depth[a]){
        swap(a,b);
    }

    for( int i=18;i>=0;i--){
        if(up[a][i]!=-1 && depth[up[a][i]]>=depth[b]){
            a=up[a][i];
        }
    }

    if(a==b){
        return b;
    }

    for( int i=18;i>=0;i--){
        if(up[a][i]!=-1 && up[b][i]!=-1 && up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}
void dfs2( int node, int parent ,vector<int>adj[]){
        for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            dfs2(it,node,adj);
            cnt[node]+=cnt[it];
        }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    depth.assign(n+1,0);
    for( int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    up.assign(n+1,vector<int>(19,-1));
    dfs(1,-1,adj);
    for( int k=1;k<19;k++){
        for( int i=1;i<=n;i++){
             int mid=up[i][k-1];
             if(mid!=-1){
                up[i][k]=up[mid][k-1];
             }
        }
    }
    cnt.assign(n+1,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        int l=lca(a,b);
        cnt[a]++;
        cnt[b]++;
        cnt[l]--;
        if(up[l][0]!=-1){
            cnt[up[l][0]]--;
        }
    }
    dfs2(1,-1,adj);
    for( int i=1;i<=n;i++){
        cout << cnt[i] << '\n';
    }
    return 0;


}