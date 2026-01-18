#include<bits/stdc++.h>
using namespace std;

bool canplace(int r, int c, vector<vector<char>>& v, int a, int b) {
    if (v[r][c] == '*')
        return false;

    int row = r;
    int col = c - 1;

    // left
    while (col >= 0) {
        if (v[row][col] == 'Q')
            return false;
        col--;
    }

    // left-up
    row = r - 1;
    col = c - 1;
    while (row >= 0 && col >= 0) {
        if (v[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // left-down
    row = r + 1;
    col = c - 1;
    while (row < a && col >= 0) {
        if (v[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

int solve(int col, vector<vector<char>>& v, int a, int b) {
    if (col == b)
        return 1;

    int cnt = 0;
    for (int i = 0; i < a; i++) {
        if (canplace(i, col, v, a, b)) {
            v[i][col] = 'Q';
            cnt += solve(col + 1, v, a, b);
            v[i][col] = '.';
        }
    }
    return cnt;
}

int main() {
    vector<vector<char>> board(8, vector<char>(8));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    cout << solve(0, board, 8, 8) << endl;
    return 0;
}
