#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
class fenwick
{
public:
    int n;
    vector<long long> bits;
    fenwick(int n)
    {
        this->n = n;
        bits.assign(n + 1, 0);
    }
    void add(int i, long long v)
    {
        while (i <= n)
        {
            bits[i] = (bits[i] + v) % mod;
            i += (i & -i);
        }
    }
    long long sum(int i)
    {
        long long res = 0;
        while (i > 0)
        {
            res = (res + bits[i]) % mod;
            i -= (i & -i);
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<long long> v(n), y;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        y.push_back(v[i]);
    }

    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()));
    for (int i = 0; i < n; i++)
    {
        int ind = lower_bound(y.begin(),y.end(), v[i]) - y.begin() + 1;
        v[i] = ind;
    }

    fenwick f(y.size());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long dp = (f.sum(v[i] - 1) + 1) % mod;
        f.add(v[i], dp);
        ans = (ans + dp) % mod;
    }
    cout << ans << endl;
    return 0;
}