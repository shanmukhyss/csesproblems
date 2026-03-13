#include <bits/stdc++.h>
using namespace std;
 
class KMP{
public:
 
    vector<int> buildLPS(string &pattern){
        int m = pattern.length();
        vector<int> lps(m,0);
 
        int len = 0;
        int i = 1;
 
        while(i < m){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
 
        return lps;
    }
 
    int search(string &s, string &pattern){
        int n = s.length();
        int m = pattern.length();
 
        vector<int> lps = buildLPS(pattern);
 
        int i = 0;
        int j = 0;
        int ans = 0;
 
        while(i < n){
 
            if(s[i] == pattern[j]){
                i++;
                j++;
            }
 
            if(j == m){
                ans++;
                j = lps[j-1];
            }
            else if(i < n && s[i] != pattern[j]){
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
 
        return ans;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    cin >> s;
 
    string pattern;
    cin >> pattern;
 
    KMP kmp;
 
    cout << kmp.search(s, pattern) << "\n";
 
    return 0;
}