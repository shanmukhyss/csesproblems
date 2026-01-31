#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 10000000;

    // Store representation of c^2 + d^2
    vector<pair<int,int>> twoSquares(MAXN + 1, {-1, -1});

    // Precompute all c^2 + d^2
    for (int c = 0; c * c <= MAXN; c++) {
        for (int d = 0; c * c + d * d <= MAXN; d++) {
            int v = c * c + d * d;
            if (twoSquares[v].first == -1) {
                twoSquares[v] = {c, d};
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        bool found = false;

        for (int a = 0; a * a <= n && !found; a++) {
            for (int b = 0; a * a + b * b <= n; b++) {
                int r = n - a * a - b * b;
                if (twoSquares[r].first != -1) {
                    auto [c, d] = twoSquares[r];
                    cout << a << " " << b << " " << c << " " << d << "\n";
                    found = true;
                    break;
                }
            }
        }
    }

    return 0;
}
