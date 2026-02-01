#include<bits/stdc++.h>
using namespace std;
long double memo[101][8][8][8][8];
bool vis[101][8][8][8][8];
int dpx[4]={-1,0,1,0};
int dpy[4]={0,1,0,-1};
long double  dfs(int steps, int x, int y, int sx, int sy){
    if(x>=8||x<0||y>=8||y<0){
        return 0.0L;
    }
    if(steps==0){
        if(x==sx && y==sy){
            return 1.0L;
        }
        return 0.0L;
    }
    if(vis[steps][x][y][sx][sy]){
        return memo[steps][x][y][sx][sy];
    }
    vis[steps][x][y][sx][sy]=true;
    long double res=0.0L;
    for(int i=0;i<4;i++){
        int px=x-dpx[i];
        int py=y-dpy[i];
        if(px<0||px>=8||py<0||py>=8){
            continue;
        }
        int deg=0;
        for( int j=0;j<4;j++){
            int nx=px+dpx[j];
            int ny=py+dpy[j];
            if(nx>=0 && nx<8 && ny>=0 && ny<8){
                deg++;
            }
        }
        res+=dfs(steps-1,px,py,sx,sy)/deg;
    }
    return memo[steps][x][y][sx][sy]=res;
}
long double roundof(long double number){
    long double integer=floor(number);
    long double diff= number-integer;
    if(diff>0.5){
        return integer+1.0L;
    }
    else if(diff<0.5){
        return integer;
    }
    else{
        long long x=(long long)integer;
        if(x%2==0){
            return integer;
        }
        else{
            return integer+1.0L;
        }

    }
}

int main(){
    int k;
    cin>>k;
    long double expected=0.0L;
    for(int x=0;x<8;x++){
        for( int y=0;y<8;y++){
            long double prob=1.0L;
            for( int sx=0;sx<8;sx++){
                for( int sy=0;sy<8;sy++){
                    long double val= dfs(k,x,y,sx,sy);
                    prob*=(1.0L-val);
                }
            }
            expected+=prob;
        }
    }

    long double scaled=expected*1e6L;
    long double result=roundof(scaled);
    cout << fixed << setprecision(6) << result/1e6L << '\n';

    return 0;

}