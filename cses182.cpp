#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < n; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix matrixPower(Matrix base, long long exp) {
    int n = base.size();
    Matrix result(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++)
        result[i][i] = 1;

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

    Matrix adj(n, vector<long long>(n, 0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a][b]++;
    }

    Matrix Ak = matrixPower(adj, k);
    cout << Ak[0][n - 1] << "\n";

    return 0;
}
