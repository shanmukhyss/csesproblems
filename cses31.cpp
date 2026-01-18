#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    map<int, int>mpp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    bool found=false;

    for(int i=0;i<n;i++){
        if(mpp.count(x-v[i])){
            found=true;
            cout<<i+1<<" "<<mpp[x-v[i]]<<endl;
            return 0;
        }
        mpp[v[i]]=i+1;
    }

    if(!found){
    cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}