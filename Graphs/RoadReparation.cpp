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

        pq.push({c, u, v});
    }

    DSU dsu(n);

    long long result = 0;
    int edges = 0;
    while (!pq.empty())
    {
        auto [c, u, v] = pq.top();
        pq.pop();
        if (dsu.unite(u, v))
        {
            result += c;
            edges += 1;
        }
    }

    if (edges < n - 1)
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