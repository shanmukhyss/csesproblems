#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long >a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long  total=0;
    for(int i=0;i<n;i++){
        total+=a[i];
        
    }
    unordered_set<long long >st;
    st.insert(0);
    for(int i=0;i<n;i++){
        unordered_set<long long >stt;
        for(auto it:st){
           stt.insert(it);
           stt.insert(it+a[i]);
        }
        st=stt;
    }
    long long  ans=LLONG_MAX;

    for(auto it:st){
        ans=min(ans,abs(total-2*it));

    }
    cout<<ans<<endl;
    return 0;


}