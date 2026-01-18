#include<bits/stdc++.h>
using namespace std;
unordered_set<string>used;
string ans;
char ch[2] = {'0', '1'};

void dfs(string s){
    for(auto c:ch){
        string edge=s+c;
        if(!used.count(edge)){
            used.insert(edge);
            string str=edge.substr(1);
            dfs(str);
            ans.push_back(c);
        }
    }
}
int main(){
    int n;
    cin>>n;
    string start=string(n-1,'0');
    dfs(start);
    reverse(ans.begin(), ans.end()); 
    cout<<start<<ans<<endl;
    return 0;
}
