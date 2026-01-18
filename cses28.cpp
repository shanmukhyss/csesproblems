#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<long long>a(n);
    vector<long long>b(m);
    multiset<long long >s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }

    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    for(int i=0;i<m;i++){
        auto it=s.upper_bound(b[i]);
        if(it==s.begin()){
            cout<<-1<<endl;
        }
        else{
            --it;
            cout<<*it<<endl;
            s.erase(it);
        }
         

        
    }

    
    return 0;
}
