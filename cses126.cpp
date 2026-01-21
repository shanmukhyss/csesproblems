#include<bits/stdc++.h>
using namespace std;
class segment{
    public:
    int n;
    vector<int>seg;
    segment(int n){
        this->n=n;
        seg.resize(4*n);
    }
    void build(int ind, int low, int high, vector<int>&arr){
        if(low==high){
            seg[ind]=arr[low];
            return ;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
    }
    int query(int ind, int val, int low, int high){
        if(seg[ind]<val){
            return -1;
        }
        if(low==high){
            return low;
        }
        int mid=(low+high)/2;
        int p=0;
        if(seg[2*ind+1]>=val){
           p= query(2*ind+1,val,low,mid);
        }
        else{
            p= query(2*ind+2,val,mid+1,high);
        }
        return p;
    }
    void update(int ind, int val, int low, int high , int idx){
        if(low==high){
            seg[ind]-=val;
            return ;
        }
        int mid=(low+high)/2;
        if(idx>mid){
            update(2*ind+2,val,mid+1,high,idx);
        }
        else{
            update(2*ind+1,val,low,mid,idx);
        }
        seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
    }
    
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>h(n);
    vector<int>g(m);

    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<m;i++){
        cin>>g[i];
    }
    segment s(n);
    s.build(0,0,n-1,h);

    for(int i=0;i<m;i++){
        int idx=s.query(0,g[i],0,n-1);
        if(idx==-1){
            cout<<0<<" ";
        }
        else{
            cout<<idx+1<<" ";
            s.update(0,g[i],0,n-1,idx);
        }
    }
    return 0;
}