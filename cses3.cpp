#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    int l=0;
    int r=0;
    unordered_map<char,int>mp;
    int ans=0;
    while(r<n){
       mp[s[r]]++;
        while(mp.size()>1){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;    
        }
        ans=max(ans,r-l+1);
        r++;
        }
        cout<<ans<<endl;
    }
