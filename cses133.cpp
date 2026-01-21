#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    long long  sum;
    long long pref;
    long long suff;
    long long best;
    Node() {
        sum = pref = suff = best = 0;
    }
    Node(long long val){
        sum=val;
        pref=suff=best=max(val,0LL);

    }
};
class segment{
    public:
    int n;
    vector<Node>seg;
    segment(int n){
        this->n=n;
        seg.resize(4*n);
    }
    void build(int ind, int low, int high, vector<int>&arr){
        if(low==high){
            seg[ind]=Node(arr[low]);
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
    void update(int ind, int low, int high , int idx,int val){
        if(low==high){
            seg[ind]=Node(val);
            return ;
        }
        int mid=(low+high)/2;
        if(idx>mid){
            update(2*ind+2,mid+1,high,idx,val);
        }
        else{
            update(2*ind+1,low,mid,idx,val);
        }

        seg[ind].sum=seg[2*ind+1].sum + seg[2*ind+2].sum;
        seg[ind].pref=max(seg[2*ind+1].pref,seg[2*ind+1].sum+seg[2*ind+2].pref);
        seg[ind].suff=max(seg[2*ind+2].suff,seg[2*ind+2].sum+seg[2*ind+1].suff);
        seg[ind].best=max({seg[2*ind+1].best,seg[2*ind+2].best,seg[2*ind+1].suff+seg[2*ind+2].pref});

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
        int k,x;
        cin>>k>>x;
        k--;
        s.update(0,0,n-1,k,x);
        cout<<s.seg[0].best<<endl;
    }
    return 0;
}