#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    long long sum;
    long long pref;
    long long suff;
    long long best;
    node(){
        sum=pref=suff=best=0;
    }
    node(long long val){
        sum=val;
        pref=suff=best=max(val,0LL);
    }
};
class segment{
    public:
    int n;
    vector<node>seg;
    segment (int n){
       this->n=n;
       seg.resize(4*n);
    }
    void build(int ind, int low, int high,vector<int>&arr){
        if(low==high){
            seg[ind]=node(arr[low]);
            return ;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind].sum=seg[2*ind+1].sum + seg[2*ind+2].sum;
        seg[ind].pref=max(seg[2*ind+1].pref,seg[2*ind+1].sum+seg[2*ind+2].pref);
        seg[ind].suff=max(seg[2*ind+2].suff,seg[2*ind+2].sum+seg[2*ind+1].suff);
        seg[ind].best=max({seg[2*ind+1].best,seg[2*ind+2].best,seg[2*ind+1].suff+seg[2*ind+2].pref});
    }
    node queryhelper(int ind, int a, int b, int low, int high){
        if(a<=low && high<=b){
            return seg[ind];
        }
        if(low>b||high<a){
            return node(0);
        }
        int mid=(low+high)/2;
        node left=queryhelper(2*ind+1,a,b,low,mid);
        node right=queryhelper(2*ind+2,a,b,mid+1,high);
        node res;
        res.sum = left.sum + right.sum;
        res.pref = max(left.pref, left.sum + right.pref);
        res.suff = max(right.suff, right.sum + left.suff);
        res.best = max({left.best, right.best, left.suff + right.pref});
        return res;

    }
    long long query(int ind, int a, int b, int low, int high){
        return queryhelper(ind,a,b,low,high).best;
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    segment s(n);
    s.build(0,0,n-1,v);
    while(q--){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        cout << s.query(0, a, b, 0, n-1) << endl;

    }
}