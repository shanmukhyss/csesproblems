#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir[4] = {'R', 'D', 'L', 'U'};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<int>> monster_dist(n, vector<int>(m, INF));
    queue<pair<int,int>> q;
    pair<int,int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monster_dist[i][j] = 0;
                q.push({i, j});
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (monster_dist[nx][ny] > monster_dist[x][y] + 1) {
                monster_dist[nx][ny] = monster_dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<char>> parent(n, vector<char>(m));
    queue<pair<int,int>> qa;
    qa.push(start);
    dist[start.first][start.second] = 0;
    pair<int,int> end = {-1, -1};
    while (!qa.empty()) {
        auto [x, y] = qa.front(); qa.pop();
        if (x == 0 || y == 0 || x == n-1 || y == m-1) {
            end = {x, y};
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (dist[x][y] + 1 >= monster_dist[nx][ny]) continue;
            if (dist[nx][ny] != INF) continue;
            dist[nx][ny] = dist[x][y] + 1;
            parent[nx][ny] = dir[i];
            qa.push({nx, ny});
        }
    }

    if (end.first == -1) {
        cout << "NO\n";
        return 0;
    }

    string path;
    int x = end.first, y = end.second;
    while (make_pair(x, y) != start) {
        char c = parent[x][y];
        path.push_back(c);
        if (c == 'R') y--;
        else if (c == 'L') y++;
        else if (c == 'U') x++;
        else if (c == 'D') x--;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
}
