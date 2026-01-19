#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;               // destination node
    long long cap;        // remaining capacity
    int rev;              // index of reverse edge
};

vector<vector<Edge>> graph;
vector<int> level;       // BFS levels
vector<int> work;        // remembers next edge to try

// Add forward and reverse edges
void add_edge(int from, int to, long long cap) {
    graph[from].push_back({to, cap, (int)graph[to].size()});
    graph[to].push_back({from, 0, (int)graph[from].size() - 1});
}

// Build level graph using BFS
bool bfs(int start, int end) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;

    level[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            Edge &e = graph[cur][i];
            if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[cur] + 1;
                q.push(e.to);
            }
        }
    }

    return level[end] != -1;
}

// Send flow using DFS (classic version, no reference trick)
long long dfs(int cur, int end, long long flow) {
    if (cur == end) return flow;

    for (int i = work[cur]; i < graph[cur].size(); i++) {
        work[cur] = i;  // remember this edge

        Edge &e = graph[cur][i];

        if (e.cap > 0 && level[e.to] == level[cur] + 1) {
            long long pushed = dfs(e.to, end, min(flow, e.cap));

            if (pushed > 0) {
                e.cap -= pushed;
                graph[e.to][e.rev].cap += pushed;
                return pushed;
            }
        }
    }

    work[cur] = graph[cur].size(); // no more edges to try
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    level.resize(n + 1);
    work.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }

    long long max_speed = 0;

    while (bfs(1, n)) {
        fill(work.begin(), work.end(), 0);

        while (true) {
            long long flow = dfs(1, n, LLONG_MAX);
            if (flow == 0) break;
            max_speed += flow;
        }
    }

    cout << max_speed << "\n";
    return 0;
}
