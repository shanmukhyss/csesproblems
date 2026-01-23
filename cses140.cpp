#include <bits/stdc++.h>
using namespace std;

class segment {
public:
    int n;
    vector<long long> seg;
    vector<long long> lazy_add;
    vector<long long> lazy_set;
    vector<bool> has_set;

    segment(int n) {
        this->n = n;
        seg.assign(4*n, 0);
        lazy_add.assign(4*n, 0);
        lazy_set.assign(4*n, 0);
        has_set.assign(4*n, false);
    }

    void build(int ind, int low, int high, vector<long long>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    // range add
    void update_add(int ind, int low, int high, int a, int b, long long val) {

        if (has_set[ind]) {
            seg[ind] = (high - low + 1) * lazy_set[ind];
            if (low != high) {
                has_set[2*ind+1] = has_set[2*ind+2] = true;
                lazy_set[2*ind+1] = lazy_set[2*ind+2] = lazy_set[ind];
                lazy_add[2*ind+1] = lazy_add[2*ind+2] = 0;
            }
            has_set[ind] = false;
        }

        if (lazy_add[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy_add[ind];
            if (low != high) {
                lazy_add[2*ind+1] += lazy_add[ind];
                lazy_add[2*ind+2] += lazy_add[ind];
            }
            lazy_add[ind] = 0;
        }

        if (low > b || high < a) return;

        if (a <= low && high <= b) {
            seg[ind] += (high - low + 1) * val;
            if (low != high) {
                lazy_add[2*ind+1] += val;
                lazy_add[2*ind+2] += val;
            }
            return;
        }

        int mid = (low + high) >> 1;
        update_add(2*ind+1, low, mid, a, b, val);
        update_add(2*ind+2, mid+1, high, a, b, val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    // range set
    void update_set(int ind, int low, int high, int a, int b, long long val) {

        if (has_set[ind]) {
            seg[ind] = (high - low + 1) * lazy_set[ind];
            if (low != high) {
                has_set[2*ind+1] = has_set[2*ind+2] = true;
                lazy_set[2*ind+1] = lazy_set[2*ind+2] = lazy_set[ind];
                lazy_add[2*ind+1] = lazy_add[2*ind+2] = 0;
            }
            has_set[ind] = false;
        }

        if (lazy_add[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy_add[ind];
            if (low != high) {
                lazy_add[2*ind+1] += lazy_add[ind];
                lazy_add[2*ind+2] += lazy_add[ind];
            }
            lazy_add[ind] = 0;
        }

        if (low > b || high < a) return;

        if (a <= low && high <= b) {
            seg[ind] = (high - low + 1) * val;
            if (low != high) {
                has_set[2*ind+1] = has_set[2*ind+2] = true;
                lazy_set[2*ind+1] = lazy_set[2*ind+2] = val;
                lazy_add[2*ind+1] = lazy_add[2*ind+2] = 0;
            }
            return;
        }

        int mid = (low + high) >> 1;
        update_set(2*ind+1, low, mid, a, b, val);
        update_set(2*ind+2, mid+1, high, a, b, val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    long long query(int ind, int low, int high, int a, int b) {

        if (has_set[ind]) {
            seg[ind] = (high - low + 1) * lazy_set[ind];
            if (low != high) {
                has_set[2*ind+1] = has_set[2*ind+2] = true;
                lazy_set[2*ind+1] = lazy_set[2*ind+2] = lazy_set[ind];
                lazy_add[2*ind+1] = lazy_add[2*ind+2] = 0;
            }
            has_set[ind] = false;
        }

        if (lazy_add[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy_add[ind];
            if (low != high) {
                lazy_add[2*ind+1] += lazy_add[ind];
                lazy_add[2*ind+2] += lazy_add[ind];
            }
            lazy_add[ind] = 0;
        }

        if (low > b || high < a) return 0;

        if (a <= low && high <= b)
            return seg[ind];

        int mid = (low + high) >> 1;
        return query(2*ind+1, low, mid, a, b) +
               query(2*ind+2, mid+1, high, a, b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    segment st(n);
    st.build(0, 0, n-1, arr);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            long long x;
            cin >> a >> b >> x;
            st.update_add(0, 0, n-1, a-1, b-1, x);
        }
        else if (type == 2) {
            int a, b;
            long long x;
            cin >> a >> b >> x;
            st.update_set(0, 0, n-1, a-1, b-1, x);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << st.query(0, 0, n-1, a-1, b-1) << '\n';
        }
    }
    return 0;
}
