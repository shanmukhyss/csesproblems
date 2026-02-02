#include<bits/stdc++.h>
using namespace std;
long double roundof(long double number){
    long double integer=floor(number);
    long double diff= number-integer;
    if(diff>0.5){
        return integer+1.0L;
    }
    else if(diff<0.5){
        return integer;
    }
    else{
        long long x=(long long)integer;
        if(x%2==0){
            return integer;
        }
        else{
            return integer+1.0L;
        }
 
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>r(n+1);
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    long double expected=0.0L;
    for( int i=1;i<=n;i++){
        for( int j=i+1;j<=n;j++){
            int ra=r[i];
            int rb=r[j];
            int m=min(ra,rb);
            long double res=(long double)(ra*m)-(long double)(m*(m+1)/2);
            expected += res/(long double)(ra*rb);
 
        }
    }
    expected+=1e-12L;
    long double scaled=expected*1e6L;
    long double ans=roundof(scaled);
    cout<<fixed<<setprecision(6)<<(ans/1e6L)-1e-12L<<'\n';
    return 0;
}