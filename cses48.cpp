#include<bits/stdc++.h>
using namespace std;
bool compare(vector<long long >&a, vector<long long >&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<long long>>v(n,vector<long long>(2));

    for(int i=0;i<n;i++){
        cin>>v[i][0];
        cin>>v[i][1];
    }

   sort(v.begin(),v.end(),compare);
   long long ans=0;
   long long f=0;
   for(int i=0;i<n;i++){
     f+=v[i][0];
     if(f>v[i][1]){
        ans-=abs(v[i][1]-f);
     }
     else{
        ans+=abs(v[i][1]-f);
     }
     
   }

   cout<<ans<<endl;
   return 0;
}