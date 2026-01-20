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
    long long build(int ind, int low, int high, vector<int>&arr){
        if(low==high){
            seg[ind]=arr[low];
            return seg[ind];
        }
        int mid=(low+high)/2;
        long long left= build(2*ind+1,low,mid, arr);
        long long right=build(2*ind+2,mid+1,high,arr);
        seg[ind]=min(left,right);
        return seg[ind];
    }
    long long query(int ind, int l, int r, int low, int high ){
        if(l>high||r<low){
            return LONG_LONG_MAX;
        }
      if (l <= low && high <= r) {
          return seg[ind];
      }

        int mid=(low+high)/2;
        long long left=query(2*ind+1,l,r,low,mid);
        long long right=query(2*ind+2,l,r,mid+1,high);
        return min(left,right);
    }
    long long update(int ind, int val , int idx, int low, int high,vector<int>&arr){
        if(low==high){
            arr[idx]=val;
            seg[ind]=val;
            return seg[ind];
        }
        int mid=(low+high)/2;
        if(idx>mid){
            update(2*ind+2,val,idx,mid+1,high,arr);
        }
        else{
            update(2*ind+1,val,idx,low,mid,arr);
        }
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
        return seg[ind];
        
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
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1){
            a--;
            s.update(0,b,a,0,n-1,v);
        }
        else{
            a--;
            b--;
            cout<<s.query(0,a,b,0,n-1)<<endl;
        }
    }
    return 0;
}