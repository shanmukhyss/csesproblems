#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long find(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    for (int i = 0; i < 32; i++) {
        if (exp & (1LL << i)) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long exponent = find(b, c, MOD - 1);

        long long answer = find(a, exponent, MOD);

        cout << answer << '\n';
    }

    return 0;
}
