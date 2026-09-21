// CF 1922B - Forming Triangles
// Lengths are powers of two => a triple works iff its two largest are equal.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll c2(ll k) { return k * (k - 1) / 2; }
ll c3(ll k) { return k * (k - 1) * (k - 2) / 6; }

void solve()
{
    int n;
    cin >> n;
    vector<ll> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }

    ll ans = 0, below = 0;
    for (int v = 0; v <= n; v++)
    {
        ans += c2(cnt[v]) * below; // two of length 2^v + one strictly smaller
        ans += c3(cnt[v]);         // three of length 2^v (equilateral)
        below += cnt[v];           // must come last
    }
    cout << ans << '\n';
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
