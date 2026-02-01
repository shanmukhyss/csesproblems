#include <bits/stdc++.h>
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long double expected = 0.0;
    for (int m = 1; m <= k; ++m)
    {
        long double p = pow((long double)(m - 1) / k, n);
        expected += 1.0 - p;
    }
    long double scaled=expected*1e6L;
    long double ans=roundof(scaled);
    cout<<fixed<<setprecision(6)<<ans/1e6L<<'\n';
    return 0;
}