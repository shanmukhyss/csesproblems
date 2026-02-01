#include <bits/stdc++.h>
using namespace std;
bool triangular(long long  x) {
    if (x < 0) return false;
    long long  d = 1 + 8 * x;
    long long  s = sqrtl(d);
    return s * s == d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long  n;
        cin >> n;

        if (triangular(n)) {
            cout << 1 << '\n';
            continue;
        }

        bool ok = false;
        for (long long  k = 1; k * (k + 1) / 2 <= n; k++) {
            long long  Tk = k * (k + 1) / 2;
            if (triangular(n - Tk)) {
                cout << 2 << '\n';
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << 3 << '\n';
        }
    }

    return 0;
}
