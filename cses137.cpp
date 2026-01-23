#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int full = 19;

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    vector<int> nxt(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && v[st.top()] <= v[i]) {
            st.pop();
        }
        if (!st.empty()) nxt[i] = st.top();
        st.push(i);
    }

    // 🔧 FIX: allocate n+1 nodes
    vector<vector<int>> up(n + 1, vector<int>(full, n));
    vector<vector<long long>> sum(n + 1, vector<long long>(full, 0));

    for (int i = 0; i < n; i++) {
        up[i][0] = nxt[i];
        sum[i][0] = 1LL * (nxt[i] - i) * v[i];
    }

    // sentinel node
    for (int k = 0; k < full; k++) {
        up[n][k] = n;
        sum[n][k] = 0;
    }

    for (int k = 1; k < full; k++) {
        for (int i = 0; i <= n; i++) {
            up[i][k] = up[up[i][k - 1]][k - 1];
            sum[i][k] = sum[i][k - 1] + sum[up[i][k - 1]][k - 1];
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        int pos = a;
        long long res = 0;

        for (int i = full - 1; i >= 0; i--) {
            if (up[pos][i] <= b + 1) {
                res += sum[pos][i];
                pos = up[pos][i];
            }
        }

        if (pos <= b) {
            res += 1LL * v[pos] * (b - pos + 1);
        }

        long long original = prefix[b + 1] - prefix[a];
        cout << res - original << "\n";
    }

    return 0;
}
