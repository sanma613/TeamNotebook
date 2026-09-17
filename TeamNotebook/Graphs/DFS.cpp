#include <bits/stdc++.h>

using namespace std;

void dfs(int u, const vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v, adj, visited);
        }
    }
}