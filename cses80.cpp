#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
vector<vector<int>>dp;
int n,m;
void dfs(int row, int mask, int nextmask, int col){
    if(row==n){
        dp[nextmask][col+1]=(dp[nextmask][col+1]+dp[mask][col])%mod;
        return ;
    }

    if(mask & (1<<row)){
        dfs(row+1,mask,nextmask,col);
    }
    else{
        
        if(row+1<n && !(mask & (1<<(row+1)))){
            dfs(row+2,mask,nextmask,col);
        }
        dfs(row+1,mask,nextmask|(1<<row),col);
    }
}
int main(){
    cin>>n>>m;
    int full=1<<n;
    dp.assign(full,vector<int>(m+1,0));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int mask=0;mask<full;mask++){
            if(dp[mask][i]){
                dfs(0,mask,0,i);
            }
        }
    }
    cout<<dp[0][m]<<endl;
    
}