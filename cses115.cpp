#include<bits/stdc++.h>
using namespace std;
class edge{
    public:
    int to;
    long long cap;
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
        graph.resize(n+1);
        level.assign(n+1,-1);
        work.resize(n+1);
    }

    void add(int u, int v, int c){
        graph[u].push_back({v,c,graph[v].size()});
        graph[v].push_back({u,0,graph[u].size()-1});
    }

    bool bfs(int start, int end){
        level.assign(n+1,-1);
        level[start]=0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto &e:graph[curr]){
                if(e.cap>0 && level[e.to]== -1){
                    level[e.to] = level[curr]+1;
                    q.push(e.to);
                }
            }                      
       }
        return level[end]!=-1;
    }

    long long dfs( int start , int end , long long flow){
        if(start==end){
            return flow;
        }

       for(int i=work[start];i<graph[start].size();i++){
            work[start]=i;
            edge &e = graph[start][i];
            if(e.cap>0 && level[e.to]== level[start]+1){
                long long pushed= dfs(e.to,end,min(flow,e.cap));
                if(pushed>0){
                    e.cap-=pushed;
                    graph[e.to][e.rev].cap+=pushed;
                    return pushed;
                }
            }
       }
       work[start]=graph[start].size();
       return 0;
    }
};



int main(){
    int n,m;
    cin>>n>>m;
    dinic d(n);

    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        d.add(a,b,c);
    }
    long long ans=0;
    while(d.bfs(1,n)){
        d.work.assign(n+1,0);
        while(true){
           long long  flow=d.dfs(1,n,LONG_LONG_MAX);
            if(flow==0){
                break;
            }
            ans+=flow;
        }
    }
    cout<<ans<<endl;
    return 0;
}