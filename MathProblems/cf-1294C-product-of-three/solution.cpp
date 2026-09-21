// CF 1294C - Product of Three Numbers
// Greedy: smallest divisor >= 2 for a, then smallest divisor of n/a that differs.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;

    ll a = -1;
    for (ll d = 2; d * d <= n; d++)
        if (n % d == 0)
        {
            a = d;
            break;
        }
    if (a == -1)
    {
        cout << "NO\n"; // n is prime
        return;
    }

    ll m = n / a;
    ll b = -1;
    for (ll d = 2; d * d <= m; d++)
        if (m % d == 0 && d != a)
        {
            b = d;
            break;
        }
    if (b == -1)
    {
        cout << "NO\n";
        return;
    }

    ll c = m / b;
    if (c >= 2 && c != a && c != b)
        cout << "YES\n"
             << a << ' ' << b << ' ' << c << '\n';
    else
        cout << "NO\n";
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
