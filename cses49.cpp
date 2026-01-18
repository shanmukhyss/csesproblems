#include <bits/stdc++.h>
using namespace std;

bool check(const vector<long long> &times, long long mid)
{
    long long sum = 0;
    long long mx = 0;

    for (long long t : times)
    {
        sum += t;
        mx = max(mx, t);
    }
    if (mid < sum) return false;
    if (mid < 2 * mx) return false;

    return true;
}


int main()
{
    int n;
    cin >> n;

    vector<long long> times(n);
    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
    }

    long long low = 1, high = 1e15;
    long long ans = LONG_LONG_MAX;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (check(times, mid))
        {
            ans = min(mid,ans);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
