#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<char>> ans(n, vector<char>(m));
    char colors[4] = {'A', 'B', 'C', 'D'};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (char c : colors) {
                if (c == grid[i][j]) continue;
                if (i > 0 && ans[i-1][j] == c) continue;
                if (j > 0 && ans[i][j-1] == c) continue;

                ans[i][j] = c;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
