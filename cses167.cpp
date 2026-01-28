#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    int k;
    cin>>n>>k;
    vector<long long>a(k);
    for( int i=0;i<k;i++){
        cin>>a[i];
    }
    long long answer=0;
    for(int mask=1;mask<(1<<k);mask++){
        __int128 product=1;
        int bits=0;
        for( int i=0;i<k;i++){
            if(mask & (1<<i)){
                bits++;
                product*=a[i];
                if(product>n){
                    break;
                }
            }
        }
        if(product>n){
            continue;
        }
        long long count=n/(long long)product;
        if(bits%2==0){
            answer-=count;
        }
        else{
           answer+=count;
        }
    }
    cout<<answer<<'\n';
    return 0;
}