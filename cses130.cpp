#include<bits/stdc++.h>
using namespace std;
class prefix{
    public:
    int n;
    vector<long long>seg;
    prefix(int n){
        this->n=n;
        seg.resize(4*n);
    }
    void build(int ind, int low, int high, vector<int>&arr){
        if(low==high){
            seg[ind]=arr[low]- low - 1 ;
            return ;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    void update(int ind, int low, int high, int idx, int val){
           if(low==high){
               seg[ind]=val -idx -1;
               return ;
           }
           int mid=(low+high)/2;
           if(idx>mid){
             update(2*ind+2,mid+1,high,idx,val);
           }
           else{
             update(2*ind+1,low,mid,idx,val);
           }
           seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    long long  query(int ind, int low, int high, int a, int b){
        if(a<=low && high<=b){
            return seg[ind];
        }
        if(low>b||high<a){
            return LLONG_MAX;
        }
        int mid=(low+high)/2;
        long long left=query(2*ind+1,low,mid,a,b);
        long long right=query(2*ind+2,mid+1,high,a,b);
        return min(left,right);
        
    }
};

class suffix{
    public:
    int n;
    vector<long long>seg;
    suffix(int n){
        this->n=n;
        seg.resize(4*n);
    }
    void build(int ind, int low, int high, vector<int>&arr){
        if(low==high){
            seg[ind]=arr[low] + low + 1 ;
            return ;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    void update(int ind, int low, int high, int idx, int val){
           if(low==high){
               seg[ind]=val + idx + 1;
               return ;
           }
           int mid=(low+high)/2;
           if(idx>mid){
             update(2*ind+2,mid+1,high,idx,val);
           }
           else{
             update(2*ind+1,low,mid,idx,val);
           }
           seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    long long  query(int ind, int low, int high, int a, int b){
        if(a<=low && high<=b){
            return seg[ind];
        }
        if(low>b||high<a){
            return LLONG_MAX;
        }
        int mid=(low+high)/2;
        long long left=query(2*ind+1,low,mid,a,b);
        long long right=query(2*ind+2,mid+1,high,a,b);
        return min(left,right);
        
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>pizza(n);
    for(int i=0;i<n;i++){
        cin>>pizza[i];
    }
    prefix p(n);
    suffix s(n);
    p.build(0,0,n-1,pizza);
    s.build(0,0,n-1,pizza);
    while(q--){
        int a;
        cin>>a;
        int ans=INT_MAX;
        if(a==1){
            int k;
            int x;
            cin>>k>>x;
            k--;
            p.update(0,0,n-1,k,x);
            s.update(0,0,n-1,k,x);
        }
        else{
           int k;
           cin>>k;
           k--;
           int ans1=p.query(0,0,n-1,0,k);
           int ans2=s.query(0,0,n-1,k,n-1);
           ans=min(k+ans1+1,ans2-k-1);
           cout<<ans<<endl;
        }

    }
}