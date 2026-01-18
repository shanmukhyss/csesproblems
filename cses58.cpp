#include<bits/stdc++.h>
using namespace std;
bool compare(vector<long long>&a, vector<long long>&b){
    return a[1]<b[1];
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<long long>>v(n,vector<long long>(2));
    for(int i=0;i<n;i++){
        cin>>v[i][0];
        cin>>v[i][1];
    }
    long long count=0;
    sort(v.begin(),v.end(),compare);
    multiset<long long>s;


    for(auto it:v){
        long long start=it[0];
        long long end=it[1];

        auto itt=s.upper_bound(start);
        if(itt!=s.begin()){
            count++;
            --itt;
            s.insert(end);
            s.erase(itt);

        }
        else if(s.size()<k){
            count++;
            s.insert(end);
        }
    }
    cout<<count<<endl;
    return 0;
}