#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int l=0;
    int r=0;
    long long  count=0;
    map<long long, int>mpp;
    while(r<n){

        while(mpp.find(v[r])!=mpp.end()){
            mpp[v[l]]--;
            if(mpp[v[l]]==0){
                mpp.erase(v[l]);
            }
            l++;
        }
        mpp[v[r]]++;
        count+=r-l+1;
        r++;

    }

    cout<<count<<endl;
    return 0;
}