#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
struct Node{
    int next[26];
    bool end;
    Node(){
        memset(next, -1 , sizeof(next));
        end=false;
    }
};
class Trie{
    public:
    vector<Node>t;
    Trie(){
        t.push_back(Node());
    }

    void insert(string &word){
        int node=0;
        for(auto c:word){
            int id= c-'a';
            if(t[node].next[id]==-1){
                t[node].next[id]=t.size();
                t.push_back(Node());
            }
            node=t[node].next[id];
        }
        t[node].end=true;
    }
    long long countWays(string s){
        int n=s.length();
        vector<long long>dp(n+1,0);
        dp[0]=1;
        for( int i=0;i<n;i++){
            if(dp[i]==0){
                continue;
            }
            int node=0;
            for( int j=i;j<n;j++){
               int id=s[j]-'a';
               if(t[node].next[id]==-1){
                  break;
               }
               node=t[node].next[id];
               if(t[node].end){
                    dp[j+1] = (dp[j+1] + dp[i]) % MOD;
                }
            }
        }
        return dp[n];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int k;
    cin >> k;
    Trie trie;
    for (int i = 0; i < k; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }
    cout << trie.countWays(s) << "\n";
    return 0;
}