#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long x = 0;
        for (int i = 1; i <= n; i++) {
            long long p;
            cin >> p;
            if (i % 2 == 0) {
                x ^= p;
            }
        }

        if (x != 0) cout << "first\n";
        else cout << "second\n";
    }
    return 0;
}
