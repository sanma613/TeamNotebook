#include <bits/stdc++.h>
using namespace std;

// BFS con reconstrucción de camino (Message Route)
void bfs(int src, int n, const vector<vector<int>> &adj)
{
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // Reconstrucción de camino hacia 'target':
    // int curr = target;
    // vector<int> path;
    // while (curr != -1) { path.push_back(curr); curr = parent[curr]; }
    // reverse(path.begin(), path.end());
}