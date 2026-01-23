#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum;
    Node *left, *right;
    Node(long long s = 0, Node* l = nullptr, Node* r = nullptr)
        : sum(s), left(l), right(r) {}
};

int n, q;
vector<Node*> roots;

/* Build initial segment tree */
Node* build(int l, int r, const vector<int>& arr) {
    if (l == r)
        return new Node(arr[l]);
    int mid = (l + r) / 2;
    Node* left = build(l, mid, arr);
    Node* right = build(mid + 1, r, arr);
    return new Node(left->sum + right->sum, left, right);
}

/* Persistent point update */
Node* update(Node* prev, int l, int r, int pos, int val) {
    if (l == r)
        return new Node(val);
    int mid = (l + r) / 2;
    if (pos <= mid) {
        Node* left = update(prev->left, l, mid, pos, val);
        return new Node(left->sum + prev->right->sum, left, prev->right);
    } else {
        Node* right = update(prev->right, mid + 1, r, pos, val);
        return new Node(prev->left->sum + right->sum, prev->left, right);
    }
}

/* Range sum query */
long long query(Node* node, int l, int r, int ql, int qr) {
    if (!node || qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return node->sum;
    int mid = (l + r) / 2;
    return query(node->left, l, mid, ql, qr)
         + query(node->right, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    roots.push_back(build(1, n, arr));

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, a, x;
            cin >> k >> a >> x;
            --k;
            roots[k] = update(roots[k], 1, n, a, x);
        } 
        else if (type == 2) {
            int k, a, b;
            cin >> k >> a >> b;
            --k;
            cout << query(roots[k], 1, n, a, b) << "\n";
        } 
        else {
            int k;
            cin >> k;
            --k;
            roots.push_back(roots[k]);
        }
    }
    return 0;
}
