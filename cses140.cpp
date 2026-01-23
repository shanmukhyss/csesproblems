#include <bits/stdc++.h>
using namespace std;

vector<long long> seg;
vector<long long> lazy_add;
vector<long long> lazy_set;
vector<bool> has_set;

void build(int ind, int low, int high, vector<long long> &arr)
{
    if (low == high) {
        seg[ind] = arr[low];
        return;
    }

    int mid = (low + high) >> 1;
    build(2*ind+1, low, mid, arr);
    build(2*ind+2, mid+1, high, arr);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

void push(int ind, int low, int high)
{
    if (low == high) return;

    int left = 2*ind+1;
    int right = 2*ind+2;
    int mid = (low + high) >> 1;

    // push set
    if (has_set[ind]) {
        seg[left]  = (long long)(mid - low + 1) * lazy_set[ind];
        seg[right] = (long long)(high - mid) * lazy_set[ind];

        has_set[left] = has_set[right] = true;
        lazy_set[left] = lazy_set[right] = lazy_set[ind];
        lazy_add[left] = lazy_add[right] = 0;

        has_set[ind] = false;
    }

    // push add
    if (lazy_add[ind] != 0) {
        seg[left]  += (long long)(mid - low + 1) * lazy_add[ind];
        seg[right] += (long long)(high - mid) * lazy_add[ind];

        lazy_add[left] += lazy_add[ind];
        lazy_add[right] += lazy_add[ind];

        lazy_add[ind] = 0;
    }
}

void range_add(int ind, int low, int high, int l, int r, long long val)
{
    if (r < low || l > high) return;

    if (l <= low && high <= r) {
        seg[ind] += (long long)(high - low + 1) * val;
        lazy_add[ind] += val;
        return;
    }

    push(ind, low, high);
    int mid = (low + high) >> 1;

    range_add(2*ind+1, low, mid, l, r, val);
    range_add(2*ind+2, mid+1, high, l, r, val);

    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

void range_set(int ind, int low, int high, int l, int r, long long val)
{
    if (r < low || l > high) return;

    if (l <= low && high <= r) {
        seg[ind] = (long long)(high - low + 1) * val;
        has_set[ind] = true;
        lazy_set[ind] = val;
        lazy_add[ind] = 0;
        return;
    }

    push(ind, low, high);
    int mid = (low + high) >> 1;

    range_set(2*ind+1, low, mid, l, r, val);
    range_set(2*ind+2, mid+1, high, l, r, val);

    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

long long range_sum(int ind, int low, int high, int l, int r)
{
    if (r < low || l > high) return 0;

    if (l <= low && high <= r)
        return seg[ind];

    push(ind, low, high);
    int mid = (low + high) >> 1;

    return range_sum(2*ind+1, low, mid, l, r) +
           range_sum(2*ind+2, mid+1, high, l, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    seg.assign(4*n, 0);
    lazy_add.assign(4*n, 0);
    lazy_set.assign(4*n, 0);
    has_set.assign(4*n, false);

    build(0, 0, n-1, arr);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            long long x;
            cin >> a >> b >> x;
            range_add(0, 0, n-1, a-1, b-1, x);
        }
        else if (type == 2) {
            int a, b;
            long long x;
            cin >> a >> b >> x;
            range_set(0, 0, n-1, a-1, b-1, x);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << range_sum(0, 0, n-1, a-1, b-1) << '\n';
        }
    }
}
