#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1e9 + 7;
static const int MAXA = 1e6;

long long fact[MAXA + 1], inv_fact[MAXA + 1];

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i <= MAXA; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAXA] = modpow(fact[MAXA], MOD - 2);
    for (int i = MAXA; i > 0; i--)
        inv_fact[i - 1] = inv_fact[i] * i % MOD;

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        long long ans = fact[a];
        ans = ans * inv_fact[b] % MOD;
        ans = ans * inv_fact[a - b] % MOD;
        cout << ans << "\n";
    }
}
