#include <bits/stdc++.h>
using namespace std;
long long INF = (long long)4e18;
struct Matrix {
    int n;
    vector<vector<long long>> a;
    Matrix(int n) {
        this->n = n;
        a.assign(n, vector<long long>(n, INF));
    }
    Matrix(int n, bool identity) {
        this->n = n;
        a.assign(n, vector<long long>(n, INF));
        if (identity) {
            for (int i = 0; i < n; i++)
                a[i][i] = 0;
        }
    }
};
Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.n;
    Matrix C(n);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A.a[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (B.a[k][j] == INF) continue;
                C.a[i][j] = min(C.a[i][j], A.a[i][k] + B.a[k][j]);
            }
        }
    }
    return C;
}


Matrix matrixpower(Matrix base, long long exp) {
    int n = base.n;
    Matrix result(n, true); 

    while (exp > 0) {
        if (exp & 1)
            result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    Matrix adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        adj.a[u][v] = min(adj.a[u][v], w); 
    }

    Matrix res = matrixpower(adj, k);

    long long ans = res.a[0][n - 1];
    if (ans ==INF)
        cout << -1 << "\n";   
    else
        cout << ans << "\n";

    return 0;
}
