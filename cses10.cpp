#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long trail = 0;
    for(long long i = 5; i <= n; i *= 5) {
        trail += n / i;
    }

    cout << trail << endl;
}
