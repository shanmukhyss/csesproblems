#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,x;
    cin>>n>>x;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
   map<long long ,int >mpp;
   long long prefix=0;
   long long cnt=0;
   mpp[0]=1;
   for(int i=0;i<n;i++){
     prefix+=v[i];
     if(mpp.count(prefix-x)){
        cnt+=mpp[prefix-x];
     }
     mpp[prefix]++;
      
   }
   cout<<cnt<<endl;
    return 0;
 
}