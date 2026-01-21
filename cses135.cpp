#include<bits/stdc++.h>
using namespace std;
class fenwick {
public:
    int n;
    vector<int> bit;
    fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void add(int i, int v) {
        while (i <= n) {
            bit[i] += v;
            i += i & -i;
        }
    }
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
};
bool compare( const vector<int>&a,const vector<int>&b){
    return a[0]>b[0];
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<vector<int>>queries(q,vector<int>(3));
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        queries[i]={a,b,i};
    }
    fenwick fw(n);
    sort(queries.begin(),queries.end(),compare);
    int curr=n;
    map<int, int>mpp;
    vector<int>ans(q);
    for(auto qr:queries){
        int l=qr[0];
        int r=qr[1];
        int id=qr[2];
        while(curr>=l){
            if(mpp.count(v[curr])){
                fw.add(mpp[v[curr]],-1);
            }
            fw.add(curr,1);
            mpp[v[curr]]=curr;
            curr--;
        }
        ans[id]=fw.sum(r)-fw.sum(l-1);
    }

    for(auto x:ans){
        cout<<x<<endl;
    }
}