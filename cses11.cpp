#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int total = a + b;
        int mini = min(a, b);
        int maxi = max(a, b);
        if (total % 3 == 0 && maxi <= 2 * mini)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}