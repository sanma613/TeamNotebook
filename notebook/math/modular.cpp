// Modular arithmetic: fast power, inverse, safe add/sub/mul.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007; // 998244353 is the other common one

ll madd(ll a, ll b) { return (a + b) % MOD; }
ll msub(ll a, ll b) { return ((a - b) % MOD + MOD) % MOD; } // keep it non-negative
ll mmul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

// Fast exponentiation: O(log e).
ll mpow(ll b, ll e, ll m = MOD)
{
    ll r = 1 % m;
    b %= m;
    if (b < 0)
        b += m;
    while (e > 0)
    {
        if (e & 1)
            r = (__int128)r * b % m;
        b = (__int128)b * b % m;
        e >>= 1;
    }
    return r;
}

// Inverse via Fermat. Requires m PRIME and a not divisible by m.
ll minv(ll a, ll m = MOD) { return mpow(a, m - 2, m); }

// Extended Euclid: returns g = gcd(a,b) and x, y with a*x + b*y = g.
ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Inverse for a NON-prime modulus. Requires gcd(a, m) == 1; returns -1 otherwise.
ll minv_general(ll a, ll m)
{
    ll x, y;
    ll g = extgcd(((a % m) + m) % m, m, x, y);
    if (g != 1)
        return -1;
    return ((x % m) + m) % m;
}

// Inverses of 1..n in O(n), when you need all of them.
vector<ll> inv_table(int n, ll m = MOD)
{
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = m - (m / i) * inv[m % i] % m;
    return inv;
}
