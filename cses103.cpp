#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        indeg[t[i]]++;
    }

    // find cycle nodes
    queue<int> q;
    vector<bool> incycle(n + 1, true);

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int v = q.front(); q.pop();
        incycle[v] = false;
        if (--indeg[t[v]] == 0) {
            q.push(t[v]);
        }
    }

    // cycle id, position, distance
    vector<int> cid(n + 1, -1);
    vector<int> dist(n + 1, -1);
    vector<int> cpos(n + 1, -1);
    vector<int> clen;

    int id = 0;
    for (int i = 1; i <= n; i++) {
        if (incycle[i] && cid[i] == -1) {
            int cur = i, p = 0;
            while (cid[cur] == -1) {
                cid[cur] = id;
                dist[cur] = 0;
                cpos[cur] = p++;
                cur = t[cur];
            }
            clen.push_back(p);
            id++;
        }
    }

    // distance to cycle
    for (int i = 1; i <= n; i++) {
        if (dist[i] == -1) {
            int cur = i;
            vector<int> path;
            while (dist[cur] == -1) {
                path.push_back(cur);
                cur = t[cur];
            }
            int d = dist[cur];
            for (int j = path.size() - 1; j >= 0; j--) {
                dist[path[j]] = ++d;
                cid[path[j]] = cid[cur];
            }
        }
    }

    // answer
    for (int i = 1; i <= n; i++) {
        cout << dist[i] + clen[cid[i]] << " ";
    }
    cout << "\n";

    return 0;
}
