// Binomials: small exact ones, and factorial tables mod p.
// Used by: CF 478B (Random Teams), CF 1922B (Forming Triangles),
//          CF 459B, CF 1520D, CF 1931D (all the "count pairs" problems).
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// --- Exact small binomials. k*(k-1) is always even, k*(k-1)*(k-2) always div by 6. ---
// int64 limits: c2 safe up to k ~ 4.3e9, c3 up to k ~ 2.5e6. Check your k.
ll c2(ll k) { return k < 2 ? 0 : k * (k - 1) / 2; }
ll c3(ll k) { return k < 3 ? 0 : k * (k - 1) / 2 * (k - 2) / 3; }

// --- Factorial tables mod p (p prime), for general nCr ---
const ll MOD = 1000000007;
const int MAXN = 200005;
ll fact[MAXN], ifact[MAXN];

ll mpow(ll b, ll e, ll m = MOD)
{
    ll r = 1 % m;
    b %= m;
    while (e > 0)
    {
        if (e & 1)
            r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

void build_factorials()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[MAXN - 1] = mpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i > 0; i--) // one inverse, then walk down: O(n) not O(n log n)
        ifact[i - 1] = ifact[i] * i % MOD;
}

ll nCr(int n, int r)
{
    if (r < 0 || r > n || n < 0)
        return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

ll nPr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * ifact[n - r] % MOD;
}

// Stars and bars: ways to write n as an ordered sum of k NON-NEGATIVE integers.
ll stars_and_bars(int n, int k) { return nCr(n + k - 1, k - 1); }
