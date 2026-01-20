#include<bits/stdc++.h>
using namespace std;
class segment{
    public:
    int n;
    vector<long long>seg;
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
        long long left=build(2*ind+1,low,mid,arr);
        long long right=build(2*ind+2,mid+1,high,arr);
        seg[ind]= left^right;
        return seg[ind];
    }
    long long query(int ind, int l , int r, int low, int high){
        if(l>high||r<low){
            return 0;
        }
        if(l<=low && high<=r){
            return seg[ind];
        }
        int mid =(low+high)/2;
        long long left=query(2*ind+1,l,r,low,mid);
        long long right=query(2*ind+2,l,r,mid+1,high);
        return left^right;

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
        cout<<s.query(0,a,b,0,n-1)<<endl;
    }
    return 0;
}