#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, long long>> edges(m);
    vector<pair<int, long long>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        edges[i] = {a, b, -x};
        adj[a].push_back({b, x});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    vector<bool> bad(n + 1, false);
    queue<int> q;

    for (auto &[u, v, w] : edges) {
        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
            bad[v] = true;
            q.push(v);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (!bad[it.first]) {
                bad[it.first] = true;
                q.push(it.first);
            }
        }
    }

    if (bad[n]) cout << -1 << endl;
    else cout << -dist[n] << endl;
}
