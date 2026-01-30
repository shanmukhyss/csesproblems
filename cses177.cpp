#include<bits/stdc++.h>
using namespace std;

int maxi = 1e6;
vector<long long> fact(maxi+1);
vector<long long> inv(maxi+1);
long long mod = 1e9+7;

long long expo(long long a, long long b){
    a %= mod;
    long long res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long nCr(long long n, long long r){
    if(r < 0 || r > n) return 0;
    return (((fact[n] * inv[r]) % mod) * inv[n-r]) % mod;
}

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    int k = s.size();

    if(n % 2 != 0){
        cout << 0 << '\n';
        return 0;
    }

    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }

    inv[n] = expo(fact[n], mod-2);
    for(int i = n-1; i >= 0; i--){
        inv[i] = (inv[i+1] * (i+1)) % mod;
    }

    int open = 0, close = 0, balance = 0;
    for(char c : s){
        if(c == '(') open++;
        else close++;
        balance = open - close;
        if(balance < 0){
            cout << 0 << '\n';
            return 0;
        }
    }

    int remaining = n - k;
    int need_open = n/2 - open;
    int need_close = n/2 - close;

    if(need_open < 0 || need_close < 0){
        cout << 0 << '\n';
        return 0;
    }

    long long ans = nCr(remaining, need_open);
    long long bad = nCr(remaining, need_open - 1);

    ans = (ans - bad + mod) % mod;
    cout << ans << '\n';
}
