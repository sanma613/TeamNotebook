// Sieve of Eratosthenes + smallest-prime-factor table.
// Build ONCE, outside any testcase loop.
// Used by: CF 230B (T-primes), CF 1881D (Divide and Equalize).
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int LIM = 1000001; // inclusive upper bound + 1

// --- Plain primality sieve: O(N log log N) ---
vector<bool> build_sieve()
{
    vector<bool> composite(LIM, false);
    composite[0] = composite[1] = true;
    for (int i = 2; (ll)i * i < LIM; i++)
        if (!composite[i])
            for (int j = i * i; j < LIM; j += i)
                composite[j] = true;
    return composite;
}

// --- Smallest prime factor: lets you factorize any x < LIM in O(log x) ---
int spf[LIM];

void build_spf()
{
    for (int i = 2; i < LIM; i++)
        if (!spf[i])
            for (int j = i; j < LIM; j += i)
                if (!spf[j])
                    spf[j] = i;
}

// Returns {prime, exponent} pairs. Requires build_spf() first. x must be < LIM.
vector<pair<int, int>> factorize(int x)
{
    vector<pair<int, int>> f;
    while (x > 1)
    {
        int p = spf[x], e = 0;
        while (x % p == 0)
        {
            x /= p;
            e++;
        }
        f.push_back({p, e});
    }
    return f;
}

// Factorize a single number too large for the table, up to ~1e18 if you have time.
// O(sqrt(x)) - use when you need one factorization, not many.
vector<pair<ll, int>> factorize_big(ll x)
{
    vector<pair<ll, int>> f;
    for (ll p = 2; p * p <= x; p++)
        if (x % p == 0)
        {
            int e = 0;
            while (x % p == 0)
            {
                x /= p;
                e++;
            }
            f.push_back({p, e});
        }
    if (x > 1)
        f.push_back({x, 1}); // leftover prime factor
    return f;
}

// Integer square root, corrected for floating point error. Never use (ll)sqrt(x) raw.
ll isqrt(ll x)
{
    ll y = (ll)sqrtl((long double)x);
    while (y > 0 && y * y > x)
        y--;
    while ((y + 1) * (y + 1) <= x)
        y++;
    return y;
}
