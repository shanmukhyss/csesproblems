#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long>v(n+1);
    map<long long ,int >mpp;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        mpp[v[i]]++;
    }

    long long total=1;
    long long mod=1e9+7;

    for(auto it:mpp){
        total*=(it.second+1);
        total=total%mod;
    }

    cout<<total-1<<endl;


 
    return 0;
}