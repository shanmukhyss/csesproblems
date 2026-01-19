#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>board;
int dx[8] = {2,2,-2,-2,1,1,-1,-1}; 
int dy[8] = {1,-1,1,-1,2,-2,2,-2};
bool check(int i, int j){
    if(i>=8||i<0||j>=8||j<0){
        return false;
    }
    return true;
}
int count(int x, int y){
   int cnt=0;
   for(int i=0;i<8;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(check(nx,ny)){

         if(board[nx][ny]==0){
             cnt++;
         }
      }
   }
   return cnt;
}
bool dfs(int x, int y , int move){
    board[x][y]=move;
    
     if(move==64){
        return true;
    }
    vector<pair<int,pair<int,int>>>next;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(check(nx,ny) && board[nx][ny]==0){
           next.push_back({count(nx,ny),{nx,ny}});
        }
    }
    sort(next.begin(),next.end());
    for(auto p:next){
        if(dfs(p.second.first,p.second.second,move+1)){
            return true;
        }
    }
    board[x][y]=0;
    return false;
}
int main(){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    board.assign(8,vector<int>(8,0));
    dfs(y,x,1);

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}