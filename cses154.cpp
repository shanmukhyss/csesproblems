#include<bits/stdc++.h>
using namespace std;
class fenwick{
    public:
    int n;
    vector<long long>bits;
    fenwick( int n){
        this->n=n;
        bits.assign(n+1,0);
    }
    void add( int i, int v){
         while(i<=n){
            bits[i]+=v;
            i+=i&-i;
         }
    }
    long long sum( int i){
        long long ans=0;
        while(i>0){
            ans+=bits[i];
            i-=i&-i;
        }
        return ans;
    }
};
int timer=0;
vector<int>tin;
vector<int>tout;
void dfs( int node, int parent, vector<int>adj[]){
    tin[node]=++timer;
    for(auto it:adj[node]){
        if(it==parent){
            continue;
        }
        dfs(it,node,adj);
    }
    tout[node]=timer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int>values(n+1);
    for( int i=1;i<=n;i++){
        cin>>values[i];
    }
    vector<int>adj[n+1];
    for( int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tin.resize(n+1);
    tout.resize(n+1);
    dfs(1,-1,adj);
    fenwick fw(n);
    
    for( int i=1;i<=n;i++){
        fw.add(tin[i],values[i]);
        fw.add(tout[i]+1,-values[i]);
    }

    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int s,x;
            cin>>s>>x;
            int diff=x-values[s];
            values[s]=x;
            fw.add(tin[s],diff);
            fw.add(tout[s]+1,-diff);
        }
        else{
            int s;
            cin>>s;
            cout<<fw.sum(tin[s])<<'\n';
        }
    }
      return 0;
}