#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    int n;
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        this->n=n;
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find(parent[node]);
    }
    bool unite(int u, int v){
        int up=find(u);
        int vp=find(v);
        if(up==vp){
            return false;
        }
        if(size[up]<=size[vp]){
            swap(up,vp);
        }
        parent[vp]=up;
        size[up]+=size[vp];
        return true;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    int prev=n;
    int mx=1;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(dsu.unite(a,b)){
            prev--;
            mx=max(mx, dsu.size[dsu.find(a)]);
        }
        cout<<prev<<" "<<mx<<"\n";
    }


}