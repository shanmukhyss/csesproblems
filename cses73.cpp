#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int>s1;
    s1.insert(0);
    for(int i=0;i<n;i++){
        set<int>s2;
        for(auto it:s1){
            s2.insert(it);
            s2.insert(it+a[i]);
        }
        s1=s2;
    }
    s1.erase(0);
    cout<<s1.size()<<endl;
    for(auto it:s1){
        cout<<it<<" ";
    }
    return 0;
}