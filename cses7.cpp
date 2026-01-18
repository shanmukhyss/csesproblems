#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        long long totalWays = (i*i)*(i*i - 1)/2;
        long long attackingWays = 4*(i - 1)*(i - 2);
        cout << totalWays - attackingWays << endl;
    }
}
