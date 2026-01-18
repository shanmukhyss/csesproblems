#include<bits/stdc++.h>
using namespace std;
long long func(vector<long long>&v, int x){
    int n=v.size();
    int r=0;
    int l=0;
    long long count=0;
    long long sum=0;
    while(r<n){
        sum+=v[r];
        while(sum>x){
            sum-=v[l];
            l++;
        }
        count+=r-l+1;
        r++;
    }
    return count;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<func(v,x)-func(v,x-1)<<endl;
    return 0;
 
}