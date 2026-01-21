#include <bits/stdc++.h>
using namespace std;

class fenwick {
public:
    int n;
    vector<long long> bits;

    fenwick(int n) {
        this->n = n;
        bits.assign(n + 1, 0);
    }

    void add(int i, int val) {
        while (i <= n) {
            bits[i] += val;
            i += i & -i;
        }
    }

    long long sum(int i) {
        long long ans = 0;
        while (i > 0) {
            ans += bits[i];
            i -= i & -i;
        }
        return ans;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        y[i] = p[i];
    }
   vector<pair<char, pair<long long, long long>>> queries;
    for (int i = 0; i < q; i++) {
        char ch;
        cin >> ch;
        if (ch == '!') {
            int k;
            long long x;
            cin >> k >> x;
            queries.push_back({ch, {k, x}});
            y.push_back(x);   
        } else {
            long long a, b;
            cin >> a >> b;
            queries.push_back({ch, {a, b}});
        }
    }

    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    int m = y.size();
    fenwick fw(m);

    for (int i = 0; i < n; i++) {
        int it = lower_bound(y.begin(), y.end(), p[i]) - y.begin();
        it++;
        if (it > 0) {
            fw.add(it, 1);
        }
    }
 
for (auto qu : queries) {
    char ch = qu.first;

    if (ch == '!') {
        int k = qu.second.first;
        long long x = qu.second.second;

        int ind = lower_bound(y.begin(), y.end(), x) - y.begin() + 1;
        int oldind = lower_bound(y.begin(), y.end(), p[k - 1]) - y.begin() + 1;

        fw.add(oldind, -1);
        fw.add(ind, 1);

        p[k - 1] = x;
    } else {
        long long a = qu.second.first;
        long long b = qu.second.second;

        if (a > b) swap(a, b);

        int ind1 = lower_bound(y.begin(), y.end(), a) - y.begin() + 1;
        int ind2 = upper_bound(y.begin(), y.end(), b) - y.begin();

        cout << fw.sum(ind2) - fw.sum(ind1 - 1) << "\n";
    }
}


    return 0;
}
