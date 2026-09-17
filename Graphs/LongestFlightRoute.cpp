#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    vector<int> dp(n + 1, -1);
    dp[1] = 1;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> parents(n + 1, -1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            in_degree[v]--;
            if (dp[u] != -1 && dp[u] + 1 > dp[v])
            {

                dp[v] = dp[u] + 1;
                parents[v] = u;
            }

            if (in_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if (dp[n] == -1)
    {
        cout << "IMPOSSIBLE" << '\n';
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

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}