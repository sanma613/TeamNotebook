#include <bits/stdc++.h>

using namespace std;
using pii = pair<long long, int>;

const long long INF = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
        {
            continue;
        }

        for (auto [w, v] : adj[u])
        {
            if (d + w < dist[v])
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}