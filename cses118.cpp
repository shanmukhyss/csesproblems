#include <bits/stdc++.h>
using namespace std;

class edge {
public:
    int to, cap, rev;
    bool isforward;
};

class dinic {
public:
    int n;
    vector<vector<edge>> graph;
    vector<int> level, work;

    dinic(int n) : n(n), graph(n+1), level(n+1), work(n+1) {}

    void add(int u, int v) {
        graph[u].push_back({v, 1, (int)graph[v].size(), true});
        graph[v].push_back({u, 0, (int)graph[u].size()-1, false});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &e : graph[u]) {
                if(level[e.to] == -1 && e.cap > 0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int t, int f) {
        if(u == t) return f;
        for(int &i = work[u]; i < graph[u].size(); i++) {
            edge &e = graph[u][i];
            if(e.cap > 0 && level[e.to] == level[u] + 1) {
                int pushed = dfs(e.to, t, min(f, e.cap));
                if(pushed) {
                    e.cap -= pushed;
                    graph[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;
        while(bfs(s, t)) {
            fill(work.begin(), work.end(), 0);
            while(int pushed = dfs(s, t, 1))
                flow += pushed;
        }
        return flow;
    }
};

int n, m;
dinic *d;

bool get_path(int u, vector<int> &path) {
    path.push_back(u);
    if(u == n) return true;

    for(auto &e : d->graph[u]) {
        if(e.isforward && e.cap == 0) {
            e.cap = -1;
            if(get_path(e.to, path))
                return true;
            e.cap = 0;
        }
    }
    path.pop_back();
    return false;
}

int main() {
    cin >> n >> m;
    d = new dinic(n);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        d->add(a, b);
    }

    int k = d->maxflow(1, n);
    cout << k << "\n";

    for(int i = 0; i < k; i++) {
        vector<int> path;
        get_path(1, path);
        cout << path.size() << "\n";
        for(int x : path) cout << x << " ";
        cout << "\n";
    }
}