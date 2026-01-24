#include <bits/stdc++.h>
using namespace std;

class node {
public:
    long long sum;
    node *left, *right;

    node() : sum(0), left(nullptr), right(nullptr) {}
};

class segment {
public:
    int n;
    segment(int n) : n(n) {}

    // FIX: build empty tree
    node* build(int low, int high) {
        node* cur = new node();
        if (low == high) return cur;
        int mid = (low + high) / 2;
        cur->left = build(low, mid);
        cur->right = build(mid + 1, high);
        return cur;
    }

    node* update(node* root, int low, int high, int pos, long long val) {
        if (low == high) {
            node* cur = new node();
            cur->sum = root->sum + val;
            return cur;
        }

        int mid = (low + high) / 2;
        node* cur = new node();

        if (pos <= mid) {
            cur->left = update(root->left, low, mid, pos, val);
            cur->right = root->right;
        } else {
            cur->left = root->left;
            cur->right = update(root->right, mid + 1, high, pos, val);
        }

        cur->sum = cur->left->sum + cur->right->sum;
        return cur;
    }

    long long query(node* L, node* R,int low, int high, int l, int r){
                     
        if (r < low || high < l) {
            return 0;
        }
        if (l <= low && high <= r){
            return R->sum - (L ? L->sum : 0);
        }

        int mid = (low + high) / 2;
        long long p=query(L ? L->left : nullptr, R->left, low, mid, l, r);
        long long q= query(L ? L->right : nullptr, R->right, mid + 1, high, l, r);
        return p+q;
             
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> x(n), comp;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        comp.push_back(x[i]);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    int m = comp.size();
    segment s(m);

    vector<node*> roots;
    roots.push_back(s.build(0, m - 1));  

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(comp.begin(), comp.end(), x[i]) - comp.begin();
        roots.push_back(s.update(roots.back(), 0, m - 1, pos, x[i]));
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;

        long long S = 0;
        while (true) {
            int idx = upper_bound(comp.begin(), comp.end(), S + 1) - comp.begin() - 1;
                     
            if (idx < 0) break;

            long long newSum = s.query(roots[a],roots[b],0, m - 1,0, idx);
            if (newSum == S) break;
            S = newSum;
        }

        cout << S + 1 << "\n";
    }
}
