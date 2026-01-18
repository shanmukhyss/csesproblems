#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> reps;

void dfs(int node){
    visited[node] = true;
    for(int next : adj[node]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main(){
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            reps.push_back(i); 
            dfs(i);
        }
    }

    int k = reps.size() - 1;
    cout << k << "\n";

    for(int i = 1; i < reps.size(); i++){
        cout << reps[i - 1] << " " << reps[i] << "\n";
    }

    return 0;
}
