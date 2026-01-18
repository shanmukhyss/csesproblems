#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
        cout << "NO" << endl;
        return;
    }
    if ((a == 0 || b == 0) && (a + b != 0)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    for (int i = a + 1; i <= a + b; i++) cout << i << " ";
    for (int i = 1; i <= a; i++) cout << i << " ";
    for (int i = a + b + 1; i <= n; i++) cout << i << " ";
    cout << endl;
}
int main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}