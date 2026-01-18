#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];

    }

    vector<int>ans;

    ans.push_back(v[0]);
 
    for(int i=1;i<n;i++){
        auto it = upper_bound(ans.begin(), ans.end(), v[i]);
        if(it==ans.end()){
            
            ans.push_back(v[i]);
        }
        else{
            *it=v[i];
        }

        
    }
    cout<<ans.size()<<endl;
    return 0;
}