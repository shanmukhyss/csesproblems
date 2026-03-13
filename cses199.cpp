#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    vector<int> borders;
    int k = pi[n - 1];

    while (k > 0) {
        borders.push_back(k);
        k = pi[k - 1];
    }

    reverse(borders.begin(), borders.end());

    for (int x : borders)
        cout << x << " ";

    return 0;
}