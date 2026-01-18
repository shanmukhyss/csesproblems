#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
vector<vector<int>>dp;
int func(int x, int y, vector<vector<char>>&v){
    int n=v.size();
    if(x>=n||x<0||y>=n||y<0||v[x][y]=='*'){
        return 0;
    }
    if(x==n-1 && y==n-1 && v[x][y]=='.'){
        return 1;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    int right=func(x,y+1,v);
    int down=func(x+1,y,v);
    return dp[x][y]=(right+down)%mod;

}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>v(n,vector<char>(n));
    dp.assign(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<func(0,0,v)<<endl;
    return 0;


}