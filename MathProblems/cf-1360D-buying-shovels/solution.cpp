// CF 1360D - Buying Shovels
// Answer = min(n/d) over divisors d of n with d <= k.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll best = n; // d = 1 always works
    for (ll d = 1; d * d <= n; d++)
    {
        if (n % d)
            continue;
        if (d <= k)
            best = min(best, n / d);
        if (n / d <= k)
            best = min(best, d);
    }
    cout << best << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
