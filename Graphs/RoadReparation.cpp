#include <bits/stdc++.h>
using namespace std;
using Edge = tuple<long long, int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}