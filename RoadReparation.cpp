#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, int>;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;

        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}