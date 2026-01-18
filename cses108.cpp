#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> radj;
stack<int> st;
vector<int> ids;

int modify(int node, bool sign){
    if(sign){
        return 2*node - 1;
    }
    return 2*node;       
}

void add(int u, int v){
    adj[u].push_back(v);
    radj[v].push_back(u);
}

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& radj, vector<bool>& visited ,int k){
    ids[node]=k;
    visited[node]=true;
    for(auto it:radj[node]){
        if(!visited[it]){
            dfs2(it,radj,visited,k);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    adj.resize(2*m+1);
    radj.resize(2*m+1);
    ids.resize(2*m+1,-1);

    vector<bool> visited(2*m+1,false);

    for(int i=0;i<n;i++){
        char ch1,ch2;
        int a,b;
        cin>>ch1>>a>>ch2>>b;
        bool sign1=(ch1=='+');
        bool sign2=(ch2=='+');
        add(modify(a,!sign1), modify(b,sign2));
        add(modify(b,!sign2), modify(a,sign1));
    }

    for(int i=1;i<=2*m;i++){
        if(!visited[i]){
            dfs(i,adj,visited);
        }
    }

    visited.assign(2*m+1,false);
    int id=1;

    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            dfs2(node,radj,visited,id);
            id++;
        }
    }

    vector<bool> values(m+1,false);

    for(int i=1;i<=2*m;i+=2){
        if(ids[i]==ids[i+1]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        values[(i/2)+1]=ids[i]>ids[i+1];
    }

    for(int i=1;i<=m;i++){
        cout<<(values[i]?'+':'-')<<" ";
    }
    return 0;
}
