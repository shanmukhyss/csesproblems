#include<bits/stdc++.h>
using namespace std;

vector<int> depth;
vector<vector<int>> up;

void dfs(int node, int parent, vector<int> adj[]) {
    up[node][0] = parent;
    for (auto it : adj[node]) {
        if (it == parent) continue;
        depth[it] = depth[node] + 1;
        dfs(it, node, adj);
    }
}

int steps(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    int da = depth[a];
    int db = depth[b];

    int cnt1=0;
    int diff = da - db;
    for (int i = 18; i >=0; i--) {
        if (up[a][i]!=-1 && depth[up[a][i]]>=depth[b]) {
            a = up[a][i];
            cnt1+=(1<<i);
        }
    }

    if (a == b) {
        return cnt1;
    }

    int cnt2=0;
    for (int i = 18; i >= 0; i--) {
        if (up[a][i] != -1 && up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
            cnt2+=(1<<i);
        }
    }

   cnt2++;
   return cnt1+2*cnt2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> adj[n + 1];
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(19, -1));


    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    dfs(1, -1, adj);


    for (int k = 1; k < 19; k++) {
        for (int i = 1; i <= n; i++) {
            int mid = up[i][k - 1];
            if (mid != -1) {
                up[i][k] = up[mid][k - 1];
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << steps(a, b) << '\n';
    }

    return 0;
}
