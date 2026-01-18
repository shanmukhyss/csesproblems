#include<bits/stdc++.h>
using namespace std;
int n,m;
int dpx[4]={0,1,0,-1};
int dpy[4]={1,0,-1,0};
bool check(int p, int q){
    if(p>=n||q>=m||p<0||q<0){
        return false;
    }
    return true;
}

void dfs(int x, int y, vector<vector<char>>&v){
    v[x][y]='#';
    for(int i=0;i<4;i++){
        int nx=x+dpx[i];
        int ny=y+dpy[i];
        if(check(nx,ny)&& v[nx][ny]=='.'){
            dfs(nx,ny,v);
        }
    }
}

int main(){
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.'){
                dfs(i,j,v);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}