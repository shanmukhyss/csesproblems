#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> children;
vector<int> sub;

int dfs(int u) {
    int cnt = 0;
    for (int v : children[u]) {
        cnt += dfs(v) + 1;
    }
    sub[u] = cnt;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    children.resize(n + 1);
    sub.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        children[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << sub[i] << " ";
    }
    cout << "\n";

    return 0;
}
