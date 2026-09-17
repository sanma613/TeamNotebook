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
        in_degree[v]++; // Cuentas cuántas flechas entran a v
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i); // Nodos listos desde el inicio
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (int v : adj[u])
        {
            in_degree[v]--;
            if (in_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    // Si no pudimos procesar todos los nodos, había un ciclo
    if ((int)ans.size() < n)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    // Optimización de E/S
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}