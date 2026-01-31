#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

/*
 Fast exponentiation:
 computes (base^exp) % MOD
*/
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

/*
 Modular inverse using Fermat's Little Theorem
 a^(MOD-2) % MOD
*/
long long modinv(long long a) {
    return modpow(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // Augmented matrix: n rows, m variables + 1 RHS
    vector<vector<long long>> a(n, vector<long long>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> where(m, -1); // which row defines variable j
    int row = 0;
    // Gaussian elimination
    for (int col = 0; col < m && row < n; col++) {
        int sel = row;
        // Find non-zero pivot
        for (int i = row; i < n; i++) {
            if (a[i][col] != 0) {
                sel = i;
                break;
            }
        }
        // No pivot in this column
        if (a[sel][col] == 0)
            continue;
        // Move pivot row up
        swap(a[sel], a[row]);
        where[col] = row;
        // Normalize pivot row
        long long inv = modinv(a[row][col]);
        for (int j = col; j <= m; j++) {
            a[row][j] = a[row][j] * inv % MOD;
        }
        // Eliminate column from other rows
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

    // Check for inconsistency
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

    // Construct solution
    vector<long long> x(m, 0);
    for (int j = 0; j < m; j++) {
        if (where[j] != -1) {
            x[j] = a[where[j]][m];
        }
    }

    // Output result
    for (int j = 0; j < m; j++) {
        cout << x[j] << " ";
    }
    cout << "\n";

    return 0;
}
