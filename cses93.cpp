#include <bits/stdc++.h>
using namespace std;
typedef tuple<long long, int, int> P;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, long long>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<vector<long long>> dist(n + 1, vector<long long>(2, LONG_LONG_MAX));
    dist[1][0] = 0;
    pq.push({0, 1, 0});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        long long dis = get<0>(it);
        int node = get<1>(it);
        int used = get<2>(it);
        if (dis > dist[node][used])
        {
            continue;
        }
        for (auto n : adj[node])
        {
            int ad = n.first;
            long long wt = n.second;
            if (dis + wt < dist[ad][used])
            {
                dist[ad][used] = dis + wt;
                pq.push({dist[ad][used], ad, used});
            }
            if (used == 0)
            {
                long long discounted = dis + (wt / 2);
                if (discounted < dist[ad][1])
                {
                    dist[ad][1] = discounted;
                    pq.push({dist[ad][1], ad, 1});
                }
            }
        }
    }

    cout << dist[n][1] << endl;
    return 0;
}