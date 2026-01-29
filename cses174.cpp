#include<bits/stdc++.h>
using namespace std;
int maxi = 20;
vector<long long> fact(maxi + 1);
int main(){
    int t;
    cin >> t;

    fact[0] = 1;
    for(int i = 1; i <= 20; i++){
        fact[i] = fact[i-1] * i;
    }

    while(t--){
        int type;
        cin >> type;

        if(type == 1){
            int n;
            long long k;
            cin >> n >> k;

            vector<int> ans;
            vector<bool> used(n+1,false);

            k--;
            long long prev = fact[n-1];
            int cnt = 0;

            while(ans.size() <= n-1){
                int q = k / prev;

                int pick;
                for(int i=1;i<=n;i++){
                    if(!used[i]){
                        if(q == 0){
                            pick = i;
                            break;
                        }
                        q--;
                    }
                }

                ans.push_back(pick);
                used[pick] = true;

                k %= prev;
                cnt++;
                prev = fact[n-cnt-1];
            }

            for(int i=1;i<=n;i++){
                if(!used[i]){
                    ans.push_back(i);
                }
            }

            for(int x : ans) cout << x << " ";
            cout << '\n';
        }
        else{
            int n;
            cin >> n;

            vector<int> v(n+1);
            for(int i=1;i<=n;i++){
                cin >> v[i];
            }

            vector<bool> used(n+1,false);
            long long ans = 1;

            for(int i=1;i<=n;i++){
                int cnt = 0;
                for(int j=1;j<v[i];j++){
                    if(!used[j]) cnt++;
                }
                ans += cnt * fact[n-i];
                used[v[i]] = true;
            }

            cout << ans << '\n';
        }
    }
    return 0;
}
