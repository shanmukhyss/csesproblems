#include<bits/stdc++.h>
using namespace std;
int answer=0;
int dfs(int node, int parent, vector<int> adj[]) {
    int max1 = 0, max2 = 0;

    for (int it : adj[node]) {
        if (it == parent) continue;
        int val = dfs(it, node, adj);

        if (val > max1) {
            max2 = max1;
            max1 = val;
        } else if (val > max2) {
            max2 = val;
        }
    }

    answer = max(answer, max1 + max2);
    return 1 + max1;
}

int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans=dfs(1,-1,adj);
    cout<<answer<<endl;
    
}