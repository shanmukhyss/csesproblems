#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> v(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }

    long long summ = 0;
    for (int i = 0; i < n - 1; i++) {
        summ += v[i];
    }

    long long total = n * (n + 1) / 2;
    cout << total - summ;

    return 0;
}
