#include<bits/stdc++.h>
using namespace std;

string path;
bool visited[9][9];
int ans = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dp[] = {'U', 'D', 'L', 'R'};

void solve(int step, int x, int y) {
    if (x == 7 && y == 1) {
        if (step == 48) ans++;
        return;
    }
    
    if (step == 48) return;
    
    if ((visited[x-1][y] && visited[x+1][y] && !visited[x][y-1] && !visited[x][y+1])) {
        return;
    }
    if ((visited[x][y-1] && visited[x][y+1] && !visited[x-1][y] && !visited[x+1][y])) {
        return;
    }
    
    if (path[step] != '?') {
        for (int i = 0; i < 4; i++) {
            if (dp[i] == path[step]) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    solve(step + 1, nx, ny);
                    visited[nx][ny] = false;
                }
                return;
            }
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                solve(step + 1, nx, ny);
                visited[nx][ny] = false;
            }
        }
    }
}

int main() {
    cin >> path;
    
    memset(visited, false, sizeof(visited));
    
    for (int i = 0; i < 9; i++) {
        visited[0][i] = true;
        visited[8][i] = true;
        visited[i][0] = true;
        visited[i][8] = true;
    }
    
    visited[1][1] = true;
    solve(0, 1, 1);
    
    cout << ans << endl;
    
    return 0;
}