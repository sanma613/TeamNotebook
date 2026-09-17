#include <bits/stdc++.h>
using namespace std;

bool dfs(int start, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans)
{
    visited[start] = 1;

    for (int edge : adj[start])
    {
        if (visited[edge] == 1)
            return false;

        if (visited[edge] == 0)
        {
            if (!dfs(edge, adj, visited, ans))
            {
                return false;
            }
        }
    }

    visited[start] = 2;
    ans.push_back(start);

    return true;
}

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
    }

    vector<int> visited(n + 1, 0);
    vector<int> ans;
    ans.reserve(n);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && !dfs(i, adj, visited, ans))
        {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < (int)ans.size(); i++)
    {
        if (i == (int)ans.size() - 1)
        {
            cout << ans[i] << '\n';
            continue;
        }

        cout << ans[i] << " ";
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