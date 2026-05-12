#include<bits/stdc++.h>
using namespace std;
vector<int> func( string s){
    int n = s.size();
    vector<int>ans(n,0);
    int i=1;
    int j=0;
    while(i<n && j<n){
        if(s[i]==s[j]){
            ans[i]=j+1;
            i++;
            j++;
        }else {
            while(j>0 && s[i]!=s[j]){
                j=ans[j-1];
            }
            if(s[i]==s[j]){
                ans[i]=j+1;
                j++;
            }
            i++;
        }
    }

    return ans;

}
int main(){
    string txt;
    cin>>txt;
    string pat;
    cin>>pat;
    string str= pat+'#'+txt;
    vector<int>lps=func(str);
    int cnt=0;
    int m= pat.size();
    for(int i=m+1;i<str.size();i++){
        if(lps[i]==m){
           cnt++;
        }
    }
    cout<<cnt<<endl;
}