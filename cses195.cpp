#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n % 3 == 1)
            cout << "second\n";
        else
            cout << "first\n";
    }
    return 0;
}
