// CF 466C - Number of Ways
// Count prefixes equal to S/3 seen so far; whenever the prefix hits 2S/3, add them.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    ll S = 0;
    for (ll &x : a)
    {
        cin >> x;
        S += x;
    }

    if (S % 3 != 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    ll t = S / 3, pref = 0, cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        pref += a[i];
        if (i == n - 1)
            break; // third part must be non-empty
        if (pref == 2 * t)
            ans += cnt; // before the cnt update, so one index is never both cuts
        if (pref == t)
            cnt++;
    }

    cout << ans << '\n';
    return 0;
}
