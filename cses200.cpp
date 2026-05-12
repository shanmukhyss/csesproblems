#include<bits/stdc++.h>
using namespace std;
vector<int> func( string s){
    int n= s.length();
    vector<int> pref(n,0);
    int i=1;
    int j=0;
    while(i<n && j<n){
        if(s[i]==s[j]){
            pref[i]=j+1;
            i++;
            j++;
        }else{
            while(j>0 && s[i]!=s[j]){
                j=pref[j-1];
            }
            if(s[i]==s[j]){
                pref[i]=j+1;
                j++;
            }
            i++;
        }
    }
    return pref;
}
int main(){
    string str;
    cin>>str;
    vector<int> lps = func(str);
    vector<int> borders;
    int n = str.length();
    int k = lps[n-1];
    while(k>0){
        borders.push_back(n-k);
        k=lps[k-1];
    }
    if(k==0) borders.push_back(n);
    sort(borders.begin(), borders.end());
    for(auto x: borders){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}