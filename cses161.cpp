#include <bits/stdc++.h>
using namespace std;

int MOD=1e9+7;

long long modpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;

    for (int i = 0; i < 32; i++) {
        if (b & (1LL << i)) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        long long a, b;
        cin >> a >> b;
        cout << modpow(a, b) << '\n';
    }
    return 0;
}
