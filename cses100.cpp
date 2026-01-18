#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9+7;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<long long> dist(n+1, INF), ways(n+1, 0);
    vector<int> minF(n+1, 1e9), maxF(n+1, -1e9);

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[1] = 0;
    ways[1] = 1;
    minF[1] = maxF[1] = 0;

    pq.push({0, 1});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w] : adj[u]){
            long long nd = d + w;

            if(nd < dist[v]){
                dist[v] = nd;
                ways[v] = ways[u];
                minF[v] = minF[u] + 1;
                maxF[v] = maxF[u] + 1;
                pq.push({nd, v});
            }
            else if(nd == dist[v]){
                ways[v] = (ways[v] + ways[u]) % MOD;
                minF[v] = min(minF[v], minF[u] + 1);
                maxF[v] = max(maxF[v], maxF[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " "
         << minF[n] << " " << maxF[n] << endl;
}
