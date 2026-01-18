#include <bits/stdc++.h>
using namespace std;
int N = 20;
vector<vector<int>> lift;
int solve(int n, int v)
{
    for(int i=0;i<=N;i++){
        if(n & (1<<i)){
            v=lift[v][i];
        }
    }
    return v;
}
int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> t(n + 1);
    lift.assign(n + 1, vector<int>(N + 1));
    vector<int>indegree(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        t[i] = a;
        lift[i][0] = a;
        indegree[a]++;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            lift[j][i] = lift[lift[j][i - 1]][i - 1];
        }
    }
    vector<int>cid(n+1,-1);
    vector<int>cpos(n+1,-1);
    vector<int>clen;
    vector<int>dist(n+1,-1);
    queue<int>q;
    vector<bool>incycle(n+1,true);
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        incycle[node]=false;
        indegree[t[node]]--;
        if(indegree[t[node]]==0){
            q.push(t[node]);
        }
    }
    int id=0;
    for(int i=1;i<=n;i++){
       if(incycle[i] && cid[i]==-1){
         int curr=i;
         int p=0;

         while(cid[curr] == -1){
            dist[curr]=0;
            cpos[curr]=p;
            p++;
            cid[curr]=id;
            curr=t[curr];
         }
         clen.push_back(p);
         id++;
     }
  }

  for(int i=1;i<=n;i++){
    if(dist[i]==-1){
        int curr=i;
        vector<int>path;
        while(dist[curr]==-1){
            path.push_back(curr);
            curr=t[curr];
        }
        int d=dist[curr];
        for(int i=path.size()-1;i>=0;i--){
            dist[path[i]]= ++d;
            cid[path[i]]=cid[curr];
        }
    }
  }

  while(Q--){
    int a,b;
    cin>>a>>b;
    if(cid[a]!=cid[b]){
        cout<<-1<<endl;
        continue;
    }
    if(dist[a]>=dist[b]){
        int d=dist[a]-dist[b];
        if(solve(d,a)==b){
           cout<<d<<endl;
           continue;
        }
    }
     if (dist[b]==0){
        int steps=dist[a];
        int pos1=cpos[b];
        int node=solve(steps,a);
        int pos2=cpos[node];
        int add=pos1-pos2;
        int len=clen[cid[b]];
        if(add<0){
          add+=len;
        }
        cout<<steps+add<<endl;

    }
    else{
        cout<<-1<<endl;
    }
 }

 return 0;

}