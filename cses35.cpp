#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    unordered_map<long long, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mpp[v[i]] = i;
    }

    int prev = mpp[1];
    int rounds = 1;
    for (int i = 2; i <= n; i++)
    {
        if (mpp[i] < prev)
        {
            rounds++;
            
        }
        prev=mpp[i];
    }

    cout << rounds << endl;
    return 0;
}