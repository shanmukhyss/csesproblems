#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>interval(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>interval[i][0];
        cin>>interval[i][1];
    }

    sort(interval.begin(),interval.end(),compare);

    int count=1;
    int prev=interval[0][1];
    for(int i=1;i<n;i++){
        if(interval[i][0]>=prev){
            count++;
            prev=interval[i][1];
        }
    }
   cout<<count<<endl;
   return 0;

    
}