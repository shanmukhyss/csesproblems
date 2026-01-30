#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

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

    long long n;
    cin >> n;

    long long n2 = n * n;

    long long a = pw(2, n2);              
    long long b = pw(2, (n2 + 1) / 2);       

    long long c;
    if (n % 2 == 0)
        c = pw(2, n2 / 4);                   
    else
        c = pw(2, n2 / 4 + 1);               

    long long ans = (a + b + 2 * c) % mod;
    ans = (ans * inv(4)) % mod;

    cout << ans << "\n";
    return 0;
}
