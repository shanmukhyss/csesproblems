#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin>>n>>a>>b;
    vector<long long>v(n);
    vector<long long >prefix(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        prefix[i+1]=prefix[i]+v[i];
    }

    long long ans=LONG_LONG_MIN;
    multiset<long long>s;
    for(int r=a-1;r<n;r++){
            s.insert(prefix[r-a+1]);
  
        if(r-b>=0){
            s.erase(s.find(prefix[r-b]));
        }
      if (!s.empty()) {
    ans = max(ans, prefix[r+1] - *s.begin());
}

    }
    cout<<ans<<endl;
    return 0;
}
