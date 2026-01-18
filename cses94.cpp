#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,long long>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int last = -1;

    for (int i = 1; i <= n; i++) {
        last = -1;
        for (auto &[u, v, wt] : edges) {
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                parent[v] = u;
                last = v;
            }
        }
    }

    if (last == -1) {
        cout << "NO\n";
        return 0;
    }

    // Move inside cycle
    for (int i = 0; i < n; i++) {
        last = parent[last];
    }

    // Collect cycle
    vector<int> ans;
    int curr = last;
    do {
        ans.push_back(curr);
        curr = parent[curr];
    } while (curr != last);

    ans.push_back(last);
    reverse(ans.begin(), ans.end());

    // Output
    cout << "YES\n";
    for (int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
