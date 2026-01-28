#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
long long mod_exp = mod - 1;

long long expo(long long a, long long b){
    a %= mod;
    long long res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin >> n;

    unordered_map<long long,long long> mpp;
    for(int i = 0; i < n; i++){
        long long x, k;
        cin >> x >> k;
        mpp[x] = k;
    }

    long long count = 1;
    for(auto it : mpp){
        count = count * (it.second + 1) % mod;
    }

    long long sum = 1;
    for(auto it : mpp){
        long long num = (expo(it.first, it.second + 1) - 1 + mod) % mod;
        long long denom = expo(it.first - 1, mod - 2);
        sum = sum * (num * denom % mod) % mod;
    }


    long long product = 1;
    long long cnt_mod = 1; 

    for(auto it : mpp){
        long long p = it.first;
        long long k = it.second;

        long long power = (k * (k + 1) / 2) % mod_exp;
        product = expo(product, k + 1);
        product = product * expo(p, power * cnt_mod % mod_exp) % mod;
        cnt_mod = cnt_mod * (k + 1) % mod_exp;
    }

    cout << count << " " << sum << " " << product << '\n';
    return 0;
}
