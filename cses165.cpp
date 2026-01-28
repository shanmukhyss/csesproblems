#include<bits/stdc++.h>
using namespace std;
long long mod= 1e9+7;
long long solve(long long a, long long b) {
    a %= mod;
    long long res = 1;
    for (int i = 0; i < 32; i++) {
        if (b & (1LL << i)) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
    }
    return res;
}
long long val=solve(2,mod-2);
long long range( long long l, long long r){
   long long p1= (((l+r)%mod)*val)%mod;
   long long p2=(r-l+1)%mod;
   long long product=(p1*p2)%mod;
   long long ans=1;
   ans=(ans*product)%mod;
   return ans;

}
int main(){
    long long n;
    cin>>n;
    long long l=1;
    long long sum=0;
    while(l<=n){
        long long k= n/l;
        long long r= n/k;
        sum = (sum+(k%mod)*range(l, r)%mod)%mod;
        l=r+1;

    }
    cout<<sum<<endl;
    return 0;
}