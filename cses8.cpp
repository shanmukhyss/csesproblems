#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long sum = n * (n + 1) / 2;
    
    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }
    
    cout<<"YES"<<endl;
    vector<int>a, b;
    if(n%4==0){
        for(int i=1;i<=n;i++){
            if(i%4==0 || i%4==1) a.push_back(i);
            else b.push_back(i);
        }
    }
    else if(n%4==3){
        for(int i=1;i<=n;i++){
            if(i%4==0 || i%4==3) a.push_back(i);
            else b.push_back(i);
        }
    }
    cout<<a.size()<<endl;
    for(int x:a){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<b.size()<<endl;
    for(int x:b){       
        cout<<x<<" ";
    }
}