#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int solve(int a, int b)
{

    if (a < b)
    {
        swap(a, b);
    }
    if (a == b)
    {
        return 0;
    }
    if (dp[a][b] != -1)
    {
        return dp[a][b];
    }
    int ans = INT_MAX;

    for (int i = 1; i < a; i++)
    {
        ans = min(ans, 1 + solve(a - i, b) + solve(i, b));
    }
    for (int i = 1; i < b; i++)
    {
        ans = min(ans, 1 + solve(a, b-i) + solve(a, i));
    }
    return dp[a][b] = ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        dp.assign(501, vector<int>(501, -1));
        cout << solve(a, b) << endl;
    }
}