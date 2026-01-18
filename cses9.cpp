#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int main() {


    long long n;
    cin >> n;

    long long result = 1;
    for (long long i = 0; i < n; i++) {
        result = (result * 2) % MOD;
    }

    cout << result << "\n";
    return 0;
}
