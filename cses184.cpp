#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long modpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return result;
}
long long modinv(long long a) {
    return modpow(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> where(m, -1);
    int row = 0;
    for (int col = 0; col < m && row < n; col++) {
        int sel = row;
        for (int i = row; i < n; i++) {
            if (a[i][col] != 0) {
                sel = i;
                break;
            }
        }
        if (a[sel][col] == 0){
            continue; 
        }     
        swap(a[sel], a[row]);
        where[col] = row;
        long long inv = modinv(a[row][col]);
        for (int j = col; j <= m; j++) {
            a[row][j] = a[row][j] * inv % MOD;
        }
        for (int i = 0; i < n; i++) {
            if (i != row && a[i][col] != 0) {
                long long factor = a[i][col];
                for (int j = col; j <= m; j++) {
                    a[i][j] = (a[i][j] - factor * a[row][j]) % MOD;
                    if (a[i][j] < 0)
                        a[i][j] += MOD;
                }
            }
        }
        row++;
    }
    for (int i = 0; i < n; i++) {
        bool allZero = true;
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero && a[i][m] != 0) {
            cout << -1 << "\n";
            return 0;
        }
    }
    vector<long long> x(m, 0);
    for (int j = 0; j < m; j++) {
        if (where[j] != -1) {
            x[j] = a[where[j]][m];
        }
    }

    for (int j = 0; j < m; j++) {
        cout << x[j] << " ";
    }
    cout << "\n";

    return 0;
}
