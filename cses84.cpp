#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> v;
bool visited[1005][1005];
pair<int,int> parent[1005][1005];
char path[1005][1005];

int dpx[4] = {0, 1, 0, -1};
int dpy[4] = {1, 0, -1, 0};
char ch[4] = {'R', 'D', 'L', 'U'};

bool check(int p, int q){
    if(p < 0 || q < 0 || p >= n || q >= m) return false;
    return true;
}

int main(){
    cin >> n >> m;
    v.assign(n, vector<char>(m));

    pair<int,int> start, end;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            if(v[i][j] == 'A') start = {i, j};
            if(v[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dpx[i];
            int ny = y + dpy[i];

            if(check(nx, ny) && !visited[nx][ny] &&
               (v[nx][ny] == '.' || v[nx][ny] == 'B')){
                
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                path[nx][ny] = ch[i];
                q.push({nx, ny});
            }
        }
    }

    if(!visited[end.first][end.second]){
        cout << "NO\n";
        return 0;
    }

    string s = "";
    pair<int,int> cur = end;

    while(cur != start){
        s.push_back(path[cur.first][cur.second]);
        cur = parent[cur.first][cur.second];
    }

    reverse(s.begin(), s.end());

    cout << "YES\n";
    cout << s.size() << "\n";
    cout << s << "\n";

    return 0;
}
