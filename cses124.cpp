#include<bits/stdc++.h>
using namespace std;
class fenwick{
    public:
    int n;
    vector<long long>bits;
    fenwick(int n){
        this->n=n;
        bits.assign(n+1,0);
    }
    void add(int ind, int val){
        while(ind<=n){
           bits[ind]+=val;
           ind += (ind & -ind);
        }
    }
    long long sum(int ind){
        long long ans=0;
        while(ind>0){
            ans+=bits[ind];
            ind -= (ind & -ind);
        }
        return ans;
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    fenwick fw(n);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int a,b;
            long long c;
            cin>>a>>b>>c;
            fw.add(a,c);
            if (b+1<= n){
                fw.add(b+1,-c);
            }
        }
        else{
            int k;
            cin>>k;
            cout<<fw.sum(k)+v[k]<<endl;
        }
    }
    return 0;
}