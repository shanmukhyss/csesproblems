#include <bits/stdc++.h>
using namespace std;
 
int n, a, b;
vector<vector<long double>> memo;
vector<vector<bool>> vis;
 
long double dfs(int i, int s) {
    if (s < 0) return 0.0L;
    if (i == 0) return (s == 0 ? 1.0L : 0.0L);
    if (vis[i][s]) return memo[i][s];
 
    vis[i][s] = true;
    long double res = 0.0L;
 
    for (int face = 1; face <= 6; ++face) {
        res += dfs(i - 1, s - face) / 6.0L;
    }
 
    return memo[i][s] = res;
}
long double round_half_even(long double x) {
    long double fl = floor(x);
    long double diff = x - fl;
 
    if (diff < 0.5L) return fl;
    if (diff > 0.5L) return fl + 1.0L;
 
    long long ifl = (long long)fl;
    if (ifl % 2 == 0)
        return fl;
    else
        return fl + 1.0L;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> a >> b;
 
    int maxSum = 6 * n;
    memo.assign(n + 1, vector<long double>(maxSum + 1, 0.0L));
    vis.assign(n + 1, vector<bool>(maxSum + 1, false));
 
    long double ans = 0.0L;
    for (int s = a; s <= b; ++s) {
        ans += dfs(n, s);
    }
 
    long double scaled = ans * 1e6L;
    long double rounded = round_half_even(scaled);
 
    cout << fixed << setprecision(6) << (rounded / 1e6L) << '\n';
    return 0;
}