#include<bits/stdc++.h>
using namespace std;

bool check(long long  mid, vector<long long >&v, int k){
    int n=v.size();
    if (v[0] > mid) return false;
    int  count=1;
    long long  value=v[0];
    for(int i=1;i<n;i++){

        if (v[i] > mid) return false;
        if(value+v[i]<=mid){
            value+=v[i];
        }
        else{
            count++;
            value=v[i];
        }

    }
    return count<=k;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long>v(n);
    long long total=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        total+=v[i];
    }

    long long low=1;
    long long high=1e15;
    long long ans=LONG_LONG_MAX;
    while(low<=high){
        long long mid=(low+high)/2;
        if(check(mid,v,k)){
            ans=min(ans,mid);
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    cout<<ans<<endl;

}