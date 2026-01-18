#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, pair<int,int>> P;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int,long long>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<long long>> mindist(n+1);
    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, {1, 0}});   // node 1, distance 0

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        long long dis = it.first;
        int node = it.second.first;

        if (mindist[node].size() >= k) continue;

        mindist[node].push_back(dis);

        for (auto e : adj[node]) {
            int ad = e.first;
            long long wt = e.second;

            if (mindist[ad].size() < k) {
                pq.push({dis + wt, {ad, 0}});
            }
        }
    }

    for (long long x : mindist[n]) {
        cout << x << " ";
    }
}
