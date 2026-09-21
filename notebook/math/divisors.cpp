// Divisor enumeration in O(sqrt n).
// Used by: CF 1294C (Product of Three Numbers), CF 1360D (Buying Shovels).
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// All divisors of n, unsorted. O(sqrt n).
vector<ll> divisors(ll n)
{
    vector<ll> d;
    for (ll i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            d.push_back(i);
            if (i != n / i) // guard against double-counting a perfect square
                d.push_back(n / i);
        }
    return d;
}

// Number of divisors, without materialising them.
int divisor_count(ll n)
{
    int c = 0;
    for (ll i = 1; i * i <= n; i++)
        if (n % i == 0)
            c += (i == n / i) ? 1 : 2;
    return c;
}

ll divisor_sum(ll n)
{
    ll s = 0;
    for (ll i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            s += i;
            if (i != n / i)
                s += n / i;
        }
    return s;
}

// Smallest divisor >= 2 (i.e. the smallest prime factor). Returns n if n is prime.
ll smallest_factor(ll n)
{
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return i;
    return n;
}

// Divisor counts for EVERY number in [0, N] at once: O(N log N).
// Prefer this over calling divisor_count() N times.
vector<int> divisor_count_table(int N)
{
    vector<int> d(N + 1, 0);
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i)
            d[j]++;
    return d;
}
