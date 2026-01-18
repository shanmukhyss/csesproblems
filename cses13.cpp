#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
  int total=1<<n;
  for(int i=0;i<total;i++){
     int gray=i^(i>>1);
     for(int j=n-1;j>=0;j--){
         cout<<((gray&(1<<j))?1:0);
     }     cout<<endl;
  }

    return 0;
}
