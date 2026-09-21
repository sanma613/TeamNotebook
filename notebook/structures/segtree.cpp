// Iterative segment tree. Point update, range query, O(log n).
// Change `merge` and `IDENTITY` to switch between sum / min / max / gcd.
// Non-recursive => short, fast, and no stack depth worries.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree
{
    int n;
    vector<ll> t;

    static constexpr ll IDENTITY = 0;                        // 0 for sum, LLONG_MAX for min
    static ll merge(ll a, ll b) { return a + b; }        // <- the only line to change

    SegTree(int n) : n(n), t(2 * n, IDENTITY) {}

    SegTree(const vector<ll> &a) : n(a.size()), t(2 * a.size())
    {
        copy(a.begin(), a.end(), t.begin() + n);
        for (int i = n - 1; i > 0; i--)
            t[i] = merge(t[2 * i], t[2 * i + 1]);
    }

    void set(int i, ll v) // assign (not add) at 0-indexed i
    {
        for (t[i += n] = v; i > 1; i >>= 1)
            t[i >> 1] = merge(t[i], t[i ^ 1]);
    }

    ll query(int l, int r) const // [l, r] inclusive, 0-indexed
    {
        ll resL = IDENTITY, resR = IDENTITY;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resL = merge(resL, t[l++]);
            if (r & 1)
                resR = merge(t[--r], resR);
        }
        return merge(resL, resR);
    }
};
// Note: resL and resR are kept separate so this stays correct for NON-commutative
// merges (matrix product, string concat). For sum/min you can use a single accumulator.
