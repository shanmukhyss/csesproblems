#include<bits/stdc++.h>
using namespace std;
bool check(vector<long long>&v, long long t,long long m){
    long long total=0;
    int n=v.size();
    for(int i=0;i<n;i++){
        total+=m/v[i];
        if(total>=t){
            return true;
        }
    }
    return false;
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    long long  low=1;
    long long  high=1e18;
    long long ans=LONG_LONG_MAX;
    while(low<=high){
        long long mid=(high+low)/2;
        if(check(v,t,mid)){
            ans=min(ans,mid);
            high=mid-1;

        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
        
}