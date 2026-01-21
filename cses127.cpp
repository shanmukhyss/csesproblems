#include<bits/stdc++.h>
using namespace std;
class fenwick{
    public:
    int n;
    vector<int>bits;
    fenwick(int n){
        this->n=n;
        bits.assign(n+1,0);
    }
    void add(int i, int val){
        while(i<=n){
            bits[i]+=val;
            i+= i & -i;
        }
    }
    int sum(int i){
        int ans=0;
        while(i>0){
            ans+=bits[i];
            i-= i & -i;
        }
        return ans;
    }

    int find(int k) {
        int pos = 0;
        for (int i = 18; i >= 0; i--) {
            int next = pos + (1 << i);
            if (next <= n && bits[next] < k) {
                k -= bits[next];
                pos = next;
            }
        }
        return pos + 1;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>v(n+1);
    vector<int>p(n+1);
    fenwick fw(n);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        fw.add(i,1);
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    for(int i=1;i<=n;i++){    
        int idx=fw.find(p[i]);
        cout<<v[idx]<<" ";
        fw.add(idx,-1);
    }
     return 0;
}
