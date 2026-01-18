#include <bits/stdc++.h>
using namespace std;
const int N=20;
pair<int, long long>best[1 << N];
int main() {
    int n;
    long long x;
    cin >> n >> x;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    best[0]={1,0};
    for(int i=1;i<(1<<n);i++){
        best[i]={n+1,0};
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                pair<int, long long>update;
                auto it=best[i^(1<<j)];
                if(it.second+v[j]<=x){
                    update={it.first,it.second+v[j]};
                }
                else{
                    update={it.first+1,v[j]};
                }
                best[i]=min(best[i],update);
            }
        }
    }
    
    cout<<best[(1<<n)-1].first<<endl;
    return 0;

    
}
