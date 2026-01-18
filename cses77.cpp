#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<long long >dp;
    for(int i=0;i<n;i++){
        auto it=lower_bound(dp.begin(),dp.end(),v[i]);
        if(it==dp.end()){
            dp.push_back(v[i]);
        }
        else{
            *it=v[i];
        }
    }
    cout<<dp.size()<<endl;
   
    return 0;
}
