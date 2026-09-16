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
    vector<int> rp_cts;

    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i])
        {
            continue;
        }

        queue<int> q;
        rp_cts.push_back(i);
        q.push(i);
        visited[i] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (visited[neighbor])
                {
                    continue;
                }
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << rp_cts.size() - 1 << '\n';
    for (int i = 1; i < rp_cts.size(); i++)
    {
        cout << rp_cts[i - 1] << ' ' << rp_cts[i] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
