#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }

    vector<bool> dp(n + 1, false);
    dp[0] = false; 

    for (int i = 1; i <= n; i++) {
        for (int move : p) {
            if (i - move >= 0 && !dp[i - move]) {
                dp[i] = true; 
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dp[i] ? 'W' : 'L');
    }
    cout << '\n';

    return 0;
}
