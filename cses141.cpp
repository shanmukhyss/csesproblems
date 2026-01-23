#include <bits/stdc++.h>
using namespace std;

class segment {
public:
    int n;
    vector<long long> seg;
    vector<long long> lazyc;
    vector<long long> lazycc;

    segment(int n) {
        this->n = n;
        seg.assign(4*n, 0);
        lazyc.assign(4*n, 0);
        lazycc.assign(4*n, 0);
    }

    long long sum(int low, int high) {
        // FIX: missing *
        return (long long)(high - low + 1) * (low + high) / 2;
    }

    void build(int ind, int low, int high, vector<long long>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void resolve(int ind, int low, int high) {
        if (lazyc[ind] != 0 || lazycc[ind] != 0) {
            seg[ind] += lazyc[ind] * sum(low, high)
                        + lazycc[ind] * (high - low + 1);

            if (low != high) {
                lazyc[2*ind+1] += lazyc[ind];
                lazyc[2*ind+2] += lazyc[ind];
                lazycc[2*ind+1] += lazycc[ind];
                lazycc[2*ind+2] += lazycc[ind];
            }
            lazyc[ind] = 0;
            lazycc[ind] = 0;
        }
    }

    void update(int ind, int low, int high, int a, int b) {
        resolve(ind, low, high);

        if (low > b || high < a) return;

        if (a <= low && high <= b) {
            lazyc[ind] += 1;
            lazycc[ind] += -(a - 1);
            resolve(ind, low, high);
            return;   // FIX: missing return
        }

        int mid = (low + high) / 2;
        update(2*ind+1, low, mid, a, b);
        update(2*ind+2, mid+1, high, a, b);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    long long query(int ind, int low, int high, int a, int b) {
        resolve(ind, low, high);

        if (low > b || high < a) return 0;

        if (a <= low && high <= b)
            return seg[ind];

        int mid = (low + high) / 2;
        return query(2*ind+1, low, mid, a, b) +
               query(2*ind+2, mid+1, high, a, b);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    segment s(n);
    s.build(0, 0, n-1, v);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            s.update(0, 0, n-1, a, b);
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << s.query(0, 0, n-1, a, b) << '\n';
        }
    }
    return 0;
}
