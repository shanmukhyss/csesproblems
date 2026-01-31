#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
struct matrix{
   long long a[6][6];
};
matrix multiply(matrix &m1 , matrix &m2){
    matrix res{};
    for(int i=0;i<6;i++){
        for( int j=0;j<6;j++){
            long long sum=0;
            for(int k=0;k<6;k++){
                sum=(sum+(m1.a[i][k]*m2.a[k][j])%mod)%mod;
            }
            res.a[i][j]=sum;
        }
    }
    return res;

}
matrix expo(matrix a, long long n){
    matrix res{};
    for(int i=0;i<6;i++){
        res.a[i][i]=1;
    }
    while(n>0){
        if(n&1){
            res=multiply(res,a);
        }
        a=multiply(a,a);
        n>>=1;
    }
    return res;
}
int main(){
   long long n;
   cin>>n;
   matrix m{};
   long long f[6] = {1, 1, 2, 4, 8, 16};
    if(n <= 5){
        cout << f[n] << '\n';
         return 0;
    }

   for( int i=0;i<6;i++){
      m.a[0][i]=1;
   }
   for( int i=1;i<6;i++){
      m.a[i][i-1]=1;
   }
   matrix mm = expo(m,n-5);

   long long ans=0;
   for( int i=0;i<6;i++){
      ans=(ans+(mm.a[0][i]*f[5-i])%mod)%mod;
   }
   cout<<ans<<'\n';
}