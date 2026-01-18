#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
vector<pair<int, int>> transitions;
int n;
void generate(int i, int left, int right) {
    if (i > n) return;
    if (i == n) {
        transitions.push_back({left, right});
        return;
    }
    generate(i + 1, left | 1 << i, right);
    generate(i + 1, left, right | 1 << i);
    generate(i + 2, left, right);
}

int main() {
    int m;
    cin >> n >> m;

    generate(0, 0, 0);

    vector<int>prev(1 << n);
    prev[0] = 1;

    for (int i = 0; i < m; ++i) {
       vector<int> cur(1 << n,0);
        for (auto [x, y] : transitions) {
            cur[y] += prev[x];
            cur[y] %= M;
        }

        prev=cur;
    }

    cout << prev[0] << endl;
}