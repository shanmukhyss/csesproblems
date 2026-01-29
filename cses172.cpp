#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int N = n + m - 1;
    int K = n - 1;

    vector<long long> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    long long ans = fact[N];
    ans = ans * modpow(fact[K], MOD - 2) % MOD;
    ans = ans * modpow(fact[N - K], MOD - 2) % MOD;

    cout << ans << "\n";
    return 0;
}
