#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<int, int>mpp;
    int l=s.length();
    for(int i=0;i<l;i++){
        mpp[s[i]-'A']++;
        if(mpp[s[i]-'A']>(l+1)/2){
            cout<<-1<<endl;
            return 0;
        }
    }
     int prev='#';
     string ans="";

    for(int k=0;k<l;k++){
        bool placed=false;
        for(int i=0;i<26;i++){
            if(mpp[i]==0){
                continue;
            }
            if(prev==char('A'+i)){
                continue;
            }
            int rest=l-k-1;
            int mx=0;
            mpp[i]--;
            for(int j=0;j<26;j++){
                mx=max(mx,mpp[j]);

            }

            if(mx<=(rest+1)/2){
                placed=true;
                ans.push_back(char('A'+i));
                prev = char('A' + i);

                break;
            }
            mpp[i]++;
        }
        if(!placed){
            cout<<-1<<endl;
            return 0;
        }

        
    }
    cout<<ans<<endl;
        return 0;
}