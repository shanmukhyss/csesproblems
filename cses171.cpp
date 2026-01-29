#include<bits/stdc++.h>
using namespace std;

int maxi = 1e6;
int mod = 1e9 + 7;

vector<long long> fact(maxi + 1);
vector<long long> inv(maxi + 1);

long long expo(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    inv[n] = expo(fact[n], mod - 2);
    for (int i = n - 1; i >= 1; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod; 
    }

    unordered_map<char, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[s[i]]++;
    }

    long long num = fact[n];
    long long denom = 1;
    for (auto it : mpp) {
        denom = (denom * inv[it.second]) % mod;
    }

    long long ans = (num * denom) % mod;
    cout << ans << '\n'; 
}
