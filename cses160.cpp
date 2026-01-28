#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll find(ll n, ll k) {
    if (n == 1) return 1;
    if (k <= (n + 1) / 2) {
        if (2 * k > n) return (2 * k) % n;
        return 2 * k;
    }
    int temp = find(n / 2, k - (n + 1) / 2);
    if (n & 1) {
        return 2 * temp + 1;
    }
    return 2 * temp - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << find(n, k) << '\n';
    }
    return 0;
}


