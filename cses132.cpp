#include <bits/stdc++.h>
using namespace std;

class fenwick {
public:
    int n;
    vector<int> bit;
    fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void add(int i, int v) {
        while (i <= n) {
            bit[i] += v;
            i += i & -i;
        }
    }
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
};

struct query {
    int a, b, val, id;
};

/* sort queries by val */
bool cmp_query(const query &q1, const query &q2) {
    return q1.val < q2.val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    vector<query> queries_d, queries_c;
    vector<long long> ans(q, 0);

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        queries_d.push_back({a, b, d, i});     // x[i] ≤ d
        queries_c.push_back({a, b, c - 1, i}); // x[i] < c
    }

    vector<pair<int,int>> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back({x[i], i});
    }
    sort(arr.begin(), arr.end());

    /* process queries */
    sort(queries_d.begin(), queries_d.end(), cmp_query);
    sort(queries_c.begin(), queries_c.end(), cmp_query);

    fenwick fw(n);
    int ptr = 0;

    // handle x[i] ≤ d
    for (auto &qr : queries_d) {
        while (ptr < n && arr[ptr].first <= qr.val) {
            fw.add(arr[ptr].second, 1);
            ptr++;
        }
        ans[qr.id] += fw.sum(qr.b) - fw.sum(qr.a - 1);
    }

    // reset for second pass
    fw = fenwick(n);
    ptr = 0;

    // handle x[i] < c
    for (auto &qr : queries_c) {
        while (ptr < n && arr[ptr].first <= qr.val) {
            fw.add(arr[ptr].second, 1);
            ptr++;
        }
        ans[qr.id] -= fw.sum(qr.b) - fw.sum(qr.a - 1);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << " ";
    }
}
