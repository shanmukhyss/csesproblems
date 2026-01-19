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
    vector<vector<edge>> graph;
    vector<int> level, work;

    dinic(int n){
        this->n = n;
        graph.resize(n);
        level.resize(n);
        work.resize(n);
    }

    void add(int u, int v, int c){
        graph[u].push_back({v, c, (int)graph[v].size()});
        graph[v].push_back({u, 0, (int)graph[u].size()-1});
    }

    bool bfs(int s, int t){
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto &e : graph[u]){
                if(level[e.to] == -1 && e.cap > 0){
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int t, int f){
        if(u == t) return f;
        for(int &i = work[u]; i < graph[u].size(); i++){
            edge &e = graph[u][i];
            if(e.cap > 0 && level[e.to] == level[u] + 1){
                int pushed = dfs(e.to, t, min(f, e.cap));
                if(pushed){
                    e.cap -= pushed;
                    graph[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t){
        int flow = 0;
        while(bfs(s, t)){
            fill(work.begin(), work.end(), 0);
            while(true){
                int pushed = dfs(s, t, INT_MAX);
                if(pushed == 0) break;
                flow += pushed;
            }
        }
        return flow;
    }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int source = 0;
    int sink = n + m + 1;
    dinic d(n + m + 2);

    // source -> boys
    for(int i = 1; i <= n; i++){
        d.add(source, i, 1);
    }

    // girls -> sink
    for(int j = 1; j <= m; j++){
        d.add(n + j, sink, 1);
    }

    // boy -> girl edges
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        d.add(a, n + b, 1);
    }

    cout << d.maxflow(source, sink) << "\n";

    // extract matching
    for(int i = 1; i <= n; i++){
        for(auto &e : d.graph[i]){
            if(e.to >= n+1 && e.to <= n+m && e.cap == 0){
                cout << i << " " << (e.to - n) << "\n";
            }
        }
    }

    return 0;
}
