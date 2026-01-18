#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int gondola = 0;
    sort(v.begin(), v.end());
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (v[i] + v[j] <= x)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }
        gondola++;
    }

    cout << gondola << endl;
    return 0;
}