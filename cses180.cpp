#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

pair<int, int> solve(long long n) {
    if (n == 0) {
        return {0, 1};
    }

    auto a = solve(n / 2);
    long long f = a.first;
    long long g = a.second;

    long long c = (f * ((2 * g % mod - f + mod) % mod)) % mod;
    long long d = (f * f % mod + g * g % mod) % mod;

    if (n % 2 == 0) {
        return {c, d};
    } else {
        return {d, (c + d) % mod};
    }
}

int main() {
    long long n;
    cin >> n;
    cout << solve(n).first << '\n';
}
