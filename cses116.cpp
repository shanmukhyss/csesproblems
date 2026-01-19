#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
    int to;
    int cap;
    int rev;
};

class dinic{
    public:
    int n;
    vector<vector<edge>>graph;
    vector<int>level;
    vector<int>work;

    dinic(int n){
        this->n=n;
        level.assign(n+1,-1);
        work.resize(n+1);
        graph.resize(n+1);
    }

    void add(int u, int v, int c){
        graph[u].push_back({v,c,(int)graph[v].size()});
        graph[v].push_back({u,0,(int)graph[u].size()-1});
    }

    bool bfs(int start , int end){
        level.assign(n+1,-1);
        level[start]=0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto &e : graph[curr]){
                if(level[e.to]==-1 && e.cap>0){
                    level[e.to] = level[curr] + 1; // FIX
                    q.push(e.to);
                }
            }
        }
        return level[end]!=-1;
    }

    int dfs(int start, int end, int flow){
        if(start==end){
            return flow;
        }
        for(int i=work[start]; i<graph[start].size(); i++){
            work[start]=i;
            edge &e = graph[start][i]; // FIX
            if(e.cap>0 && level[e.to]==level[start]+1){
                int cut=dfs(e.to,end,min(flow,e.cap));
                if(cut>0){
                    e.cap-=cut;
                    graph[e.to][e.rev].cap+=cut;
                    return cut;
                }
            }
        }
        return 0;
    }

    int maxflow(int start,int end){
        int ans=0;
        while(bfs(start,end)){
            work.assign(n+1,0);
            while(true){
                int flow=dfs(start, end, INT_MAX);
                if(flow==0){
                    break;
                }
                ans+=flow;
            }
        }
        return ans;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int, int>>edges;
    dinic d(n);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        d.add(a,b,1);
        d.add(b,a,1);
        edges.push_back({a,b});
    }

    cout<<d.maxflow(1,n)<<endl;

    queue<int>q;
    vector<int>visited(n+1,0);
    visited[1]=1;
    q.push(1);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto &e:d.graph[node]){
            if(e.cap>0 && !visited[e.to]){
                visited[e.to] = 1; // FIX
                q.push(e.to);
            }
        }
    }

    for(auto it:edges){
        if(visited[it.first]^visited[it.second]){ // FIX
            cout<<it.first<< " "<<it.second<<"\n";
        }
    }
    return 0;
}
