#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<long long, int>mpp;
    int l=0;
    int r=0;
    long long cnt=0;
    while(r<n){
        mpp[v[r]]++;
        while(mpp.size()>k){
            mpp[v[l]]--;
            if(mpp[v[l]]==0){
                mpp.erase(v[l]);
            }
            l++;
        }
        cnt+=r-l+1;
        r++;
    
    }
    cout<<cnt<<endl;
    return 0;
}