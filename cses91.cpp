#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>>dist(n+1,vector<long long>(n+1,-1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        if (dist[a][b] == -1 || dist[a][b] > c) {
               dist[a][b] = c;
               dist[b][a] = c;
        }
    }
    vector<vector<int>>qu(q,vector<int>(2));
    for(int i=0;i<q;i++){
        cin>>qu[i][0];
        cin>>qu[i][1];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                if(dist[i][k]==-1||dist[k][j]==-1){
                    continue;
                }
                else if(dist[i][j]==-1){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
                else {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for(int i=0;i<q;i++){
        cout<<dist[qu[i][0]][qu[i][1]]<<endl;
    }
    return 0;
}