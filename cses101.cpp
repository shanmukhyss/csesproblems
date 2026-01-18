#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> lift(n+1, vector<int>(N+1));

    for(int i = 1; i <= n; i++){
        cin >> lift[i][0];
    }

    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= n; i++){
            lift[i][j] = lift[lift[i][j-1]][j-1];
        }
    }

    while(q--){
        int x;
        long long k;
        cin >> x >> k;

        for(int i = 0; i <= N; i++){
            if(k & (1LL << i)){
                x = lift[x][i];
            }
        }
        cout << x << '\n';
    }

    return 0;
}
\