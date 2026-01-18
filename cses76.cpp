#include<bits/stdc++.h>
using namespace std;

vector<int> nge(vector<long long>& h){
    int n = h.size();
    stack<int> s;
    vector<int> ng(n);
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && h[s.top()] <= h[i]){
            s.pop();
        }
        ng[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    return ng;
}

vector<int> pge(vector<long long>& h){
    int n = h.size();
    stack<int> s;
    vector<int> pg(n);
    for(int i = 0; i < n; i++){
        while(!s.empty() && h[s.top()] <= h[i]){
            s.pop();
        }
        pg[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return pg;
}

int main(){
    int n;
    cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    vector<int> left = pge(h);
    vector<int> right = nge(h);

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++){
        if(left[i] != -1){
            adj[left[i]].push_back(i);
            indegree[i]++;
        }
        if(right[i] != n){
            adj[right[i]].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            dp[v] = max(dp[v], dp[u] + 1);
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
    return 0;
}
