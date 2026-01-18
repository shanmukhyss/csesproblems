#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> parent;
int cnt = 0;
bool dfs(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            parent[it] = node;
            if (dfs(it, adj, visited))
            {
                return true;
            }
        }
        else if (it != parent[node])
        {
            int ind = node;
            cnt++;
            ans.push_back(it);
            while (ind != it)
            {
                ans.push_back(ind);
                cnt++;
                ind = parent[ind];
            }

            ans.push_back(it);
            cnt++;
            return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    int mini = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mini = min({mini, a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent.assign(n + 1, -1);
    vector<bool> visited(n + 1, false);
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            parent[i] = -1;
            if (dfs(i, adj, visited))
            {
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << cnt << endl;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}