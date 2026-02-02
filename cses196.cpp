#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        bool even = true;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x % 2 != 0) {
                even = false;
            }
        }

        cout << (even ? "second" : "first") << '\n';
    }

    return 0;
}
