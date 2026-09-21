// CF 478B - Random Teams
// C(k,2) is convex: max at the most lopsided split, min at the most balanced one.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll c2(ll k) { return k * (k - 1) / 2; } // k*(k-1) is always even

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    ll mx = c2(n - m + 1); // one fat team, the rest have exactly one person

    ll q = n / m, r = n % m; // r teams of size q+1, (m-r) teams of size q
    ll mn = r * c2(q + 1) + (m - r) * c2(q);

    cout << mn << ' ' << mx << '\n';
    return 0;
}
