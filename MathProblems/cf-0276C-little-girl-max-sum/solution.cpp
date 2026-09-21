// CF 276C - Little Girl and Maximum Sum
// Difference array -> per-position query frequency.
// Rearrangement inequality -> biggest value onto the most-queried position.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    vector<ll> d(n + 2, 0); // n+2 so d[r+1] with r == n is in bounds
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        d[l]++;
        d[r + 1]--;
    }

    vector<ll> f(n);
    ll run = 0;
    for (int i = 1; i <= n; i++) // statement is 1-indexed; keep it that way
    {
        run += d[i];
        f[i - 1] = run;
    }

    sort(a.rbegin(), a.rend());
    sort(f.rbegin(), f.rend());

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * f[i];

    cout << ans << '\n';
    return 0;
}
