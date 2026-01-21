#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> tree;

    SegTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void build(const vector<long long>& a, int ind, int l, int r) {
        if (l == r) {
            tree[ind] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * ind + 1, l, mid);
        build(a, 2 * ind + 2, mid + 1, r);
        tree[ind] = max(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

    // Find leftmost index with value >= x
    int query(int ind, int l, int r, long long x) {
        if (tree[ind] < x) return -1;
        if (l == r) return l;

        int mid = (l + r) / 2;
        if (tree[2 * ind + 1] >= x)
            return query(2 * ind + 1, l, mid, x);
        else
            return query(2 * ind + 2, mid + 1, r, x);
    }

    void update(int ind, int l, int r, int pos, long long val) {
        if (l == r) {
            tree[ind] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * ind + 1, l, mid, pos, val);
        else
            update(2 * ind + 2, mid + 1, r, pos, val);

        tree[ind] = max(tree[2 * ind + 1], tree[2 * ind + 2]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    SegTree st(n);
    st.build(h, 0, 0, n - 1);

    for (int i = 0; i < m; i++) {
        long long r;
        cin >> r;

        int idx = st.query(0, 0, n - 1, r);
        if (idx == -1) {
            cout << 0 << " ";
        } else {
            cout << idx + 1 << " ";
            h[idx] -= r;
            st.update(0, 0, n - 1, idx, h[idx]);
        }
    }

    cout << "\n";
    return 0;
}
