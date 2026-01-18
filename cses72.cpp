#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& grid, char &mini, int x, int y,
           vector<pair<int,int>>& nxt) {
    int n = grid.size();

    if (x >= n || y >= n) return;  
    char letter= grid[x][y]; 

    if (letter < mini) {
        mini = grid[x][y];
        nxt.clear();
        nxt.push_back({x, y});
    } else if (letter == mini) {
        nxt.push_back({x, y});
    }
}


int main()
{
    int n;
    if(!(cin >> n)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    
    vector<pair<int,int>>lvl;
    lvl.push_back({0,0});
    cout << grid[0][0];
    
    for(int i=0; i < 2*n-2; i++){
        vector<pair<int,int>>nxt;
        char mini = '{'; 
        for(auto it : lvl){
            solve(grid, mini, it.first + 1, it.second, nxt);
            solve(grid, mini, it.first, it.second + 1, nxt);
        }
        
        if(nxt.empty()) break;
        
        cout << mini;
        sort(nxt.begin(), nxt.end());
        nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
        lvl = nxt;
    }
    cout << endl;

    return 0;
}