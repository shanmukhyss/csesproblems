#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int next[26];
    bool end;
    Node(){
        memset(next, -1 ,sizeof(next));
        end=false;
    }
};
class Trie{
    public:
    vector<Node>t;
    Trie(){
        t.push_back( Node());
    }

    void insert(string word){
        int node=0;
        for(char ch:word){
            int id= ch-'a';
            if(t[node].next[id]==-1){
                t[node].next[id]=t.size();
                t.push_back( Node());
            }
            node= t[node].next[id];
        }
        t[node].end=true;
    }

    int cnt(string word){
        int n= word.size();
        const int mod = 1e9+7;
        vector<int>dp(n+1 , 0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            int node=0;
            for(int j=i;j<n;j++){
                int id= word[j]-'a';
                if(t[node].next[id]==-1){
                   break;
                }
                node= t[node].next[id];
                if(t[node].end){
                    dp[j+1]=(dp[j+1]+dp[i])%mod;
                }
            }
        }
        return dp[n];

    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(false);
    string str;
    cin>>str;
    int k;
    cin>>k;
    vector<string>v(k);
    Trie t;
    for(int i=0;i<k;i++){
        cin>>v[i];
        t.insert(v[i]);
    }

    cout<<t.cnt(str)<<endl;
    return 0;
}