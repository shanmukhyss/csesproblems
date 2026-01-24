#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> dist;

void bfs(int node) {
    dist.assign(n + 1, -1);
    queue<int> q;
    q.push(node);
    dist[node] = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (auto it : adj[top]) {  
            if (dist[it] == -1) {
                dist[it] = dist[top] + 1;
                q.push(it);
            }
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    bfs(1);
    int A = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[A]) {
            A = i;
        }
    }


    bfs(A);
    vector<int> distA = dist;
    int B = A;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[B]) {
            B = i;
        }
    }


    bfs(B);
    vector<int> distB = dist;

    for (int i = 1; i <= n; i++) {
        cout << max(distA[i], distB[i]) << "\n";
    }
}
