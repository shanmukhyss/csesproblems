

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x,y;
        cin >> x >> y;

        long long k = max(x, y);
        long long answer;

        if (k % 2 == 0)
        {
            if (x == k)
                answer = k * k - y + 1;
            else
                answer = (k - 1) * (k - 1) + x; 
        }
        else
        {
            if (y == k)
                answer = k * k - x + 1; 
            else
                answer = (k - 1) * (k - 1) + y; 
        }
        cout << answer << endl;
    }
    return 0;
}
