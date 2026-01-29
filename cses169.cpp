#include<bits/stdc++.h>
using namespace std;

int primes[8] = {2,3,5,7,11,13,17,19};

long long expo(int a, long long d, long long mod){
    long long res = 1;
    long long base = a % mod;

    while (d > 0) {
        if (d & 1)
            res = (long long)((__int128)res * base % mod);
        base = (long long)((__int128)base * base % mod);
        d >>= 1;
    }
    return res;
}

long long modpow(long long a, long long b, long long mod){
    return (long long)((__int128)a * b % mod);
}

bool isprime(long long n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    long long d = n - 1;
    long long s = 0;

    while ((d & 1) == 0) {
        s++;
        d >>= 1;
    }

    for (auto p : primes) {
        if (p >= n) continue;

        long long x = expo(p, d, n);

        if (x == 1 || x == n - 1)
            continue;

        bool iscomposite = true;

        for (int i = 1; i < s; i++) {
            x = modpow(x, x, n);
            if (x == n - 1) {
                iscomposite = false;
                break;
            }
        }

        if (iscomposite)
            return false;
    }

    return true;
}

int main(){
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        if (n < 2) {
            cout << 2 << '\n';
            continue;
        }

        long long number = n + 1;
        if (number % 2 == 0 && number != 2)
            number++;

        while (!isprime(number)) {
            number += 2;
        }

        cout << number << '\n';
    }
}
