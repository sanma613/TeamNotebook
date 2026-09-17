#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, int>; // {distancia, nodo}
const ll INF = 1e18;

vector<ll> dijkstra(int src, int n, const vector<vector<pair<int, ll>>> &adj)
{
    vector<ll> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist; // Retorna distancias desde 'src' a todos los nodos
}