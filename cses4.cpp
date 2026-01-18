#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long prev = v[0];
    long long ans = 0;

    for (int i = 1; i < n; i++) {
        if (v[i] < prev) {
            ans += prev - v[i];
        } 
        prev=max(prev,v[i]);
    }

    cout << ans << endl;
    return 0;
}
