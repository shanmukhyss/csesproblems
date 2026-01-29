#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }

    vector<int> spf(n+1);
    for(int i=1;i<=n;i++) spf[i]=i;
    for(int i=2;i*i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }

    vector<bool> visited(n+1,false);
    unordered_map<int,int> maxPow;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            int cur=i,len=0;
            while(!visited[cur]){
                visited[cur]=true;
                cur=p[cur];
                len++;
            }
            while(len>1){
                int pr=spf[len],cnt=0;
                while(len%pr==0){
                    len/=pr;
                    cnt++;
                }
                maxPow[pr]=max(maxPow[pr],cnt);
            }
        }
    }

    long long ans=1;
    for(auto &it:maxPow){
        for(int i=0;i<it.second;i++){
            ans=(ans*it.first)%MOD;
        }
    }

    cout<<ans<<"\n";
    return 0;
}
