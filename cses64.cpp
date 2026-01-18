#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int func(int num) {
    if (num == 0) return 0;
    if (dp[num] != -1) return dp[num];

    int n = num;
    int ans = INT_MAX;

    while (n > 0) {
        int rem = n % 10;
        n /= 10;

        if (rem > 0) {  
            ans = min(ans, 1 + func(num - rem));
        }
    }

    return dp[num] = ans;
}

int main() {
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    cout << func(n) << endl;
    return 0;
}





