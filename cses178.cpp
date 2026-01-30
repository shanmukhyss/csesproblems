#include <bits/stdc++.h>
using namespace std;

 long long mod = 1e9+7;
 long long gcd(long long a, long long b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
 }

long long pw(long long a, long long b) {
    long long r = 1;
    a %= mod;
    while (b) {
        if (b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

long long inv(long long x) {
    return pw(x, mod - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long s = 0;
    for (long long k = 0; k < n; k++) {
        long long g = gcd(n, k);
        s = (s + pw(m, g)) % mod;
    }

    long long ans = (s * inv(n)) % mod;
    cout << ans << "\n";

    return 0;
}
