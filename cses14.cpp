#include<bits/stdc++.h>
using namespace std;
void solve(int m, int a , int b, int  c){
    if(m==0){
        return ;
    }
    solve(m-1,a,c,b);
    cout<<a<<" "<<c<<endl;
    solve(m-1,b,a,c);
}
int main(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    solve(n,1,2,3);
}