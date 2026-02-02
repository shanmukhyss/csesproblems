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

        long long nim_sum = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            nim_sum ^= (x % 4);
        }

        if (nim_sum == 0)
            cout << "second\n";
        else
            cout << "first\n";
    }
    return 0;
}
