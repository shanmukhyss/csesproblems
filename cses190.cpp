#include<bits/stdc++.h>
using namespace std;
 double roundof(long double number){
    double integer=floor(number);
     double diff= number-integer;
    if(diff>0.5){
        return integer+1.0;
    }
    else if(diff<0.5){
        return integer;
    }
    else{
         long x=(long)integer;
        if(x%2==0){
            return integer;
        }
        else{
            return integer+1.0;
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
     double expected=0.0L;
    for( int i=1;i<=n;i++){
        for( int j=i+1;j<=n;j++){
            int ra=r[i];
            int rb=r[j];
            int m=min(ra,rb);
            double res=(double)(ra*m)-(double)(m*(m+1.0)/2.0);
            expected += res/(double)(ra*rb);

        }
    }
     double scaled=expected*1e6;
     double ans=roundof(scaled);
     cout<<fixed<<setprecision(6)<<(ans/1e6)<<'\n';
    return 0;
}
