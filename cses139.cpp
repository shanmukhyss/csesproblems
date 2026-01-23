#include<bits/stdc++.h>
using namespace std;

class fenwick {
public:
    int n;
    vector<vector<int>> bits;

    fenwick(int n){
        this->n = n;
        bits.assign(n+1, vector<int>(n+1, 0));
    }

    void add(int x, int y, int val){
        for(int i = x; i <= n; i += i & -i){
            for(int j = y; j <= n; j += j & -j){
                bits[i][j] += val;
            }
        }
    }

    int sum(int x, int y){
        int ans = 0;
        for(int i = x; i > 0; i -= i & -i){
            for(int j = y; j > 0; j -= j & -j){
                ans += bits[i][j];
            }
        }
        return ans;
    }
};

int main(){
    int n, q;
    cin >> n >> q;

    vector<vector<char>> matrix(n+1, vector<char>(n+1));
    fenwick fw(n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == '*'){
                fw.add(i, j, 1);
            }
        }
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int y, x;
            cin >> y >> x;

            if(matrix[y][x] == '*'){
                matrix[y][x] = '.';
                fw.add(y, x, -1);
            } else {
                matrix[y][x] = '*';
                fw.add(y, x, 1);
            }
        }
        else{
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;

            cout << fw.sum(y2, x2) - fw.sum(y1-1, x2) - fw.sum(y2, x1-1) + fw.sum(y1-1, x1-1) << endl;                                  
        }
    }
    return 0;
}
