#include <bits/stdc++.h>
using namespace std;

class node {
public:
    long long sum;
    node *left, *right;

    node(long long val = 0) {
        sum = val;
        left = right = nullptr;
    }

    node(node* l, node* r) {
        left = l;
        right = r;
        sum = 0;
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

class segment {
public:
    int n;

    segment(int n) {
        this->n = n;
    }

    node* build(int low, int high, vector<int>& arr) {
        if (low == high) {
            return new node(arr[low]);
        }
        int mid = (low + high) / 2;
        node* left = build(low, mid, arr);
        node* right = build(mid + 1, high, arr);
        return new node(left, right);
    }

    node* update(node* root, int low, int high, int pos, long long val) {
        if (low == high) {
            return new node(val);
        }
        int mid = (low + high) / 2;
        if (pos <= mid) {
            node* newLeft = update(root->left, low, mid, pos, val);
            return new node(newLeft, root->right);
        } else {
            node* newRight = update(root->right, mid + 1, high, pos, val);
            return new node(root->left, newRight);
        }
    }

    long long query(node* root, int low, int high, int l, int r) {
        if (!root || r < low || high < l) return 0;
        if (l <= low && high <= r) return root->sum;
        int mid = (low + high) / 2;
        return query(root->left, low, mid, l, r) +
               query(root->right, mid + 1, high, l, r);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    segment s(n);
    vector<node*> roots;

    roots.push_back(s.build(0, n - 1, v)); // version 0

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, a;
            long long x;
            cin >> k >> a >> x;
            k--; a--;
            roots.push_back(
                s.update(roots[k], 0, n - 1, a, x)
            );
        }
        else if (type == 2) {
            int k, a, b;
            cin >> k >> a >> b;
            k--; a--; b--;
            cout << s.query(roots[k], 0, n - 1, a, b) << "\n";
        }
        else {
            int k;
            cin >> k;
            k--;
            roots.push_back(roots[k]);
        }
    }
    return 0;
}
