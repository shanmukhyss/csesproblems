#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long sum = v[0];
    long long maxsum = v[0];
    for (int i = 1; i < n; i++)
    {
        if (sum + v[i] < v[i])
        {
            sum = v[i];
        }
        else
        {
            sum += v[i];
        }
        maxsum = max(maxsum, sum);
    }
    cout << maxsum << endl;
    return 0;
}