#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
int maxi=1e6;
vector<long long>fact(maxi+1);
vector<long long>inv(maxi+1);
long long expo(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    if(n==1){
        int num=0;
        cout<<num<<endl;
        return 0;
    }
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    inv[n]=expo(fact[n],mod-2);
    for( int i=n-1;i>=1;i--){
        inv[i]=(inv[i+1]*(i+1))%mod;
    }
    long long product=fact[n];
    long long sum=1;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            sum=(sum-inv[i]+mod)%mod;
        }
        else{
            sum=(sum+inv[i])%mod;
        }
    }
    long long ans=(product*sum)%mod;
    cout<<ans<<'\n';
    return 0;

}