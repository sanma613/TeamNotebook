#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    vector<int> parents(n + 1, -1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int ngb : adj[node])
        {
            if (visited[ngb])
            {
                continue;
            }

            visited[ngb] = true;
            parents[ngb] = node;
            q.push(ngb);
        }
    }

    if (parents[n] == -1)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    int curr_node = n;
    vector<int> path;
    while (curr_node != -1)
    {
        path.push_back(curr_node);
        curr_node = parents[curr_node];
    }

    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << path[i] << "\n";
        }
        else
        {
            cout << path[i] << " ";
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}