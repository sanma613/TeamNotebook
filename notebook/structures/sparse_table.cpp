// Sparse table: O(n log n) build, O(1) query, but NO updates.
// Only valid for IDEMPOTENT operations (min, max, gcd) - not for sum.
// If the array never changes and you need min/max, this beats a segment tree.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SparseTable
{
    vector<vector<ll>> t;
    vector<int> lg;

    static ll op(ll a, ll b) { return min(a, b); } // <- min / max / __gcd

    SparseTable(const vector<ll> &a)
    {
        int n = a.size();
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int K = lg[n] + 1;
        t.assign(K, vector<ll>(n));
        t[0] = a;
        for (int k = 1; k < K; k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                t[k][i] = op(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
    }

    ll query(int l, int r) const // [l, r] inclusive, 0-indexed
    {
        int k = lg[r - l + 1];
        return op(t[k][l], t[k][r - (1 << k) + 1]); // the two blocks overlap - fine,
                                                    // which is why op must be idempotent
    }
};
