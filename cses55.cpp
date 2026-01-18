#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<long long, long long> cnt;
    cnt[0] = 1;  // empty prefix

    long long sum = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        long long mod = ((sum % n) + n) % n;
        ans += cnt[mod];
        cnt[mod]++;
    }

    cout << ans << endl;
    return 0;
}
