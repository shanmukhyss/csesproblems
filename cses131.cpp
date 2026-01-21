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

bool compare( tuple<int,int,int>& a,tuple<int,int,int>& b){             
    return get<0>(a) > get<0>(b); 
}

int main() {

    int n, q;
    cin >> n >> q;
 
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    vector<tuple<int,int,int>> queries(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a, b, i};
    }

    sort(queries.begin(), queries.end(), compare);

    fenwick fw(n);
    stack<int> st;
    vector<int> ans(q);

    int curra = n;

    for (auto &qr : queries) {
        int a = get<0>(qr);
        int b = get<1>(qr);
        int id = get<2>(qr);

        while (curra >= a) {
            while (!st.empty() && h[st.top()] <= h[curra]) {
                fw.add(st.top(), -1);
                st.pop();
            }
            st.push(curra);
            fw.add(curra, 1);
            curra--;
        }

        ans[id] = fw.sum(b) - fw.sum(a - 1);
    }

    for (int x : ans)
        cout << x << '\n';

    return 0;
}
