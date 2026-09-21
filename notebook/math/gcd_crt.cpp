// Extended Euclid, linear Diophantine, CRT.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// g = gcd(a,b), and x,y with a*x + b*y = g.
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

// Solve a*x + b*y = c. Returns false if no integer solution (c not divisible by g).
// General solution: x = x0 + t*(b/g), y = y0 - t*(a/g) for any integer t.
bool diophantine(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
{
    g = extgcd(llabs(a), llabs(b), x0, y0);
    if (c % g)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}

// CRT for two congruences: x = r1 (mod m1), x = r2 (mod m2).
// Moduli need NOT be coprime. Returns {remainder, lcm} or {-1,-1} if inconsistent.
// Watch overflow: use __int128 when m1*m2 can exceed 9.2e18.
pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2)
{
    ll p, q;
    ll g = extgcd(m1, m2, p, q);
    if ((r2 - r1) % g)
        return {-1, -1};
    ll lcm = m1 / g * m2;
    __int128 t = (__int128)(r2 - r1) / g % (m2 / g) * p % (m2 / g);
    __int128 res = r1 + (__int128)m1 * t;
    ll r = (ll)((res % lcm + lcm) % lcm);
    return {r, lcm};
}
