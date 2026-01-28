#include<bits/stdc++.h>
using namespace std;
int max=1e6;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    unordered_map<int, int>mpp;
    for( int i=0;i<n;i++){
        cin>>v[i];
        mpp[v[i]]++;
    }
    
    for( int g=1e6;g>=1;g--){
        int cnt=0;
        for( int i=g;i<=1e6;i+=g){
            cnt+=mpp[i];
            if(cnt>=2){
                cout<<g<<'\n';
                return 0;
            }
        }
    }
}