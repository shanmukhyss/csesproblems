#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>parent(n+1);
    parent[1]=-1;
    for( int i=2;i<=n;i++){
         int boss;
         cin>>boss;
         parent[i]=boss;
    }
    int full=19;
    vector<vector<int>>up(n+1,vector<int>(full,-1));
    for( int i=1;i<=n;i++){
        up[i][0]=parent[i];
    }
    for(int k=1;k<full;k++){
        for( int i=1;i<=n;i++){
            int mid=up[i][k-1];
            if(mid!=-1){
                up[i][k]=up[mid][k-1];
            }
        }
    }
    while (q--) {
    int x, k;
    cin >> x >> k;

    for (int i = 0; i < full; i++) {
        if (x == -1) break;
        if (k & (1 << i)) {
            x = up[x][i];
        }
    }
    cout << x << '\n';
}

    return 0;
}