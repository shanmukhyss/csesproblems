#include <bits/stdc++.h>
using namespace std;
typedef  pair<long long, int> P;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, long long>> adj[n+1];

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<P,vector<P>,greater<P>>pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [next, wt] : adj[node]) {
            if (dist[node] + wt < dist[next]) {
                dist[next] = dist[node] + wt;
                pq.push({dist[next], next});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
