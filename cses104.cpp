#include<bits/stdc++.h>
using namespace std;

class DSU{
    int n;
    vector<long long> parent;
    vector<long long> size;

public:
    DSU(int n){
        this->n = n;
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }

    long long find(long long node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    bool unite(long long u, long long v){
        long long ulp_u = find(u);
        long long ulp_v = find(v);
        if(ulp_u == ulp_v){
            return false;
        }
        if(size[ulp_u] <= size[ulp_v]){
            swap(ulp_u, ulp_v);
        }
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
        return true;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<array<long long,3>> edges(m);
    for(int i=0;i<m;i++){
        long long a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b};   
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int count = 0;
    long long total = 0;

    for(int i=0;i<m;i++){
        if(dsu.unite(edges[i][1], edges[i][2])){  
            count++;
            total += edges[i][0];                
        }
    }

    if(count != n-1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << total << endl;
    return 0;
}
