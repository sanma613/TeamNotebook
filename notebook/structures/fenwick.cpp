// Fenwick tree (Binary Indexed Tree). 1-indexed internally.
// Point update + prefix query in O(log n), with a much smaller constant than a segtree.
// Use it whenever the operation is invertible (sum, xor). For min/max use a segtree.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick
{
    int n;
    vector<ll> t;

    Fenwick(int n) : n(n), t(n + 1, 0) {}

    void add(int i, ll v) // 0-indexed position i
    {
        for (++i; i <= n; i += i & -i)
            t[i] += v;
    }

    ll prefix(int i) const // sum of [0..i], 0-indexed; prefix(-1) == 0
    {
        ll s = 0;
        for (++i; i > 0; i -= i & -i)
            s += t[i];
        return s;
    }

    ll range(int l, int r) const { return prefix(r) - prefix(l - 1); } // inclusive

    // Smallest index i with prefix(i) >= target. Requires all values non-negative.
    // O(log n) - much better than binary-searching over prefix().
    int lower_bound(ll target) const
    {
        int pos = 0;
        ll rem = target;
        for (int pw = 1 << (31 - __builtin_clz(n)); pw > 0; pw >>= 1)
            if (pos + pw <= n && t[pos + pw] < rem)
            {
                pos += pw;
                rem -= t[pos];
            }
        return pos; // 0-indexed answer
    }
};

// --- Range update, point query: keep a Fenwick over the DIFFERENCE array ---
struct FenwickRangeUpdate
{
    Fenwick f;

    FenwickRangeUpdate(int n) : f(n) {}

    void add(int l, int r, ll v) // add v to every index in [l, r]
    {
        f.add(l, v);
        if (r + 1 < f.n)
            f.add(r + 1, -v);
    }

    ll get(int i) const { return f.prefix(i); }
};
