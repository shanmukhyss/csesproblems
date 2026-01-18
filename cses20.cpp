#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dpx[8]={1,2,1,-2,-1,2,-1,-2};
    int dpy[8]={2,1,-2,1,2,-1,-2,-1};

    queue<pair<int, int>>q;
    q.push({0,0});
    vector<vector<int>>dist(n,vector<int>(n,-1));
    dist[0][0]=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int x=it.first;
        int y=it.second;
        for(int i=0;i<8;i++){
            int newx=x+dpx[i];
            int newy=y+dpy[i];
            if((0<=newx&&newx<n) && (0<=newy && newy<n)&& dist[newx][newy]==-1){
                dist[newx][newy]=dist[x][y]+1;
                q.push({newx,newy});

            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

}