#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, sz;

    DSU(int n)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
        sz.assign(n + 1, 1);
    }

    // Encuentra el representante del conjunto con compresión de caminos (Path Compression)
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Une dos conjuntos por tamaño (Union by Size)
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
            return true; // Se unieron exitosamente
        }
        return false; // Ya estaban en el mismo conjunto
    }

    bool same(int i, int j)
    {
        return find(i) == find(j);
    }
};