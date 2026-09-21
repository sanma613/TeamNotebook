// Prefix sums (1D, 2D) and the difference array.
// The cheapest data structure that exists. Reach for it before a Fenwick tree.
// Used by: CF 466C (Number of Ways), CF 276C (Little Girl and Maximum Sum).
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// --- 1D prefix sums: build O(n), sum of a[l..r] inclusive in O(1) ---
struct Prefix1D
{
    vector<ll> p; // p[i] = a[0] + ... + a[i-1], so p has size n+1

    Prefix1D(const vector<ll> &a) : p(a.size() + 1, 0)
    {
        for (size_t i = 0; i < a.size(); i++)
            p[i + 1] = p[i] + a[i];
    }

    ll sum(int l, int r) const { return p[r + 1] - p[l]; } // 0-indexed, inclusive
};

// --- Difference array: range add O(1), then one pass to materialise ---
// Size it n+2 so d[r+1] is in bounds when r == n-1 (or r == n if 1-indexed).
struct Diff
{
    vector<ll> d;

    Diff(int n) : d(n + 2, 0) {}

    void add(int l, int r, ll v) // add v to every index in [l, r], inclusive
    {
        d[l] += v;
        d[r + 1] -= v;
    }

    vector<ll> build(int n) // final array, index 0..n-1
    {
        vector<ll> a(n);
        ll run = 0;
        for (int i = 0; i < n; i++)
        {
            run += d[i];
            a[i] = run;
        }
        return a;
    }
};

// --- 2D prefix sums: build O(nm), rectangle sum in O(1) ---
struct Prefix2D
{
    vector<vector<ll>> p; // p[i][j] = sum of the rectangle [0..i-1] x [0..j-1]

    Prefix2D(const vector<vector<ll>> &g)
        : p(g.size() + 1, vector<ll>(g[0].size() + 1, 0))
    {
        for (size_t i = 0; i < g.size(); i++)
            for (size_t j = 0; j < g[0].size(); j++)
                p[i + 1][j + 1] = g[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
    }

    // Sum over rows [r1..r2] and columns [c1..c2], all inclusive, 0-indexed.
    ll sum(int r1, int c1, int r2, int c2) const
    {
        return p[r2 + 1][c2 + 1] - p[r1][c2 + 1] - p[r2 + 1][c1] + p[r1][c1];
    }
};
