#include<bits/stdc++.h>
using namespace std;

void func(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
      
    }
    unordered_set<char>st;
    for(int i=0;i<s.length();i++){
        if(st.count(s[i])==0){
            st.insert(s[i]);
            string ros=s.substr(0,i)+s.substr(i+1);
            func(ros,ans+s[i]);
        }

    }

    
}

int main(){
    string s;
    cin>>s;
    int l=s.length();
    int fact=1;
    for(int i=1;i<=l;i++){
        fact*=i;
    }
    unordered_map<int , int>mpp;
    for(int i=0;i<l;i++){
        mpp[s[i]]++;
    }
    int ans=fact;
    for(auto it:mpp){
          int f=1;
          for(int i=1;i<=it.second;i++){
              f*=i;
          }
          ans/=f;
    }

    cout<<ans<<endl;
    sort(s.begin(),s.end());
    func(s,"");
    return 0;

}