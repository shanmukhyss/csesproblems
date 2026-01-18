#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>&a, vector<int>&b){
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>v[i][0];
        cin>>v[i][1];
        v[i][2]=i;
    }

    vector<int>contain(n,0);
    vector<int>contained(n,0);
    sort(v.begin(),v.end(),compare);
    int maxy=0;
    int miny=INT_MAX;

    for(int i=0;i<n;i++){
        if(maxy>=v[i][1]){
            contained[v[i][2]]=1;
        }
        maxy=max(maxy,v[i][1]);

    }

    for(int i=n-1;i>=0;i--){
        if(miny<=v[i][1]){
            contain[v[i][2]]=1;
        }
        miny=min(miny,v[i][1]);
    }

    for(int i=0;i<n;i++){
        cout<<contain[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }
    return 0;
}