#include <bits/stdc++.h>
using namespace std;

int maxi = 1e6;
vector<long long> fact(maxi + 1);
vector<long long> inv(maxi + 1);
long long mod = 1e9 + 7;

long long expo(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    inv[n] = expo(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }

    int t = n / 2;
    long long num = fact[2 * t];
    long long denom = (inv[t] * inv[t + 1]) % mod;

    long long ans = (num * denom) % mod;
    cout << ans << '\n';
}
