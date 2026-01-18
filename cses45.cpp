#include <bits/stdc++.h>
using namespace std;

class Range
{
public:
    int x, y, id;
};

class fenwick
{
public:
    int n;
    vector<int> bit;

    fenwick(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int i, int v)
    {
        i++;
        while (i <= n)
        {
            bit[i] += v;
            i += i & (-i);
        }
    }

    int sum(int i)
    {
        i++;
        int ans = 0;
        while (i > 0)
        {
            ans += bit[i];
            i -= i & (-i);
        }
        return ans;
    }

    int range(int l, int r)
    {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

bool compare(Range &a, Range &b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x < b.x;
}

int main()
{
    int n;
    cin >> n;

    vector<Range> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }

    sort(a.begin(), a.end(), compare);

    // Coordinate compression for y
    vector<int> ys;
    for (int i = 0; i < n; i++)
        ys.push_back(a[i].y);

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    vector<int> contains(n, 0);
    vector<int> contained(n, 0);

    fenwick f1(ys.size());

    // Count how many ranges contain this range
    for (int i = 0; i < n; i++)
    {
        int y = lower_bound(ys.begin(), ys.end(), a[i].y) - ys.begin();
        contained[a[i].id] = f1.range(y, ys.size() - 1);
        f1.add(y, 1);
    }

    fenwick f2(ys.size());

    // Count how many ranges this range contains
    for (int i = n - 1; i >= 0; i--)
    {
        int y = lower_bound(ys.begin(), ys.end(), a[i].y) - ys.begin();
        contains[a[i].id] = f2.range(0, y);
        f2.add(y, 1);
    }

    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout << "\n";

    return 0;
}
