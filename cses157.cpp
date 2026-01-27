#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;

vector<int> tree[MAXN + 1];
int subtree_size[MAXN + 1];
int n;


void dfs(int u, int parent) {
    subtree_size[u] = 1;

    for (int v : tree[u]) {
        if (v == parent) continue;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

int find_centroid() {
    for (int u = 1; u <= n; u++) {
        bool is_centroid = true;
        for (int v : tree[u]) {
            if (subtree_size[v] < subtree_size[u]) { 
                if (subtree_size[v] > n / 2) {
                    is_centroid = false;
                    break;
                }
            }
        }

        int parent_side = n - subtree_size[u];
        if (parent_side > n / 2)
            is_centroid = false;

        if (is_centroid)
            return u;
    }

    return -1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    int centroid = find_centroid();
    cout << centroid << "\n";

    return 0;
}
