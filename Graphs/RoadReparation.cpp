#include <bits/stdc++.h>
using namespace std;
using Edge = tuple<long long, int, int>;

struct DSU
{
    vector<int> parent, sz;

    DSU(int n)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
    }

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {
            if (sz[root_i] < sz[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            return true;
        }
        return false;
    }

    bool same(int i, int j)
    {
        return find(i) == find(j);
    }
};

struct Edge
{
    int u, v;
    long long c;
    bool operator<(const Edge &other)
    {
        return c < other.c;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    edges.reserve(m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;

        edges.push_back({u, v, c});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    long long result = 0;
    int count = 0;
    for (const auto &edge : edges)
    {
        if (dsu.unite(edge.u, edge.v))
        {
            result += edge.c;
            count++;
            if (count == n - 1)
                break;
        }
    }

    if (count < n - 1)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}