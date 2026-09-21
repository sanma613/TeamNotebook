// CF 1541B - Pleasant Pairs
// a_i * a_j = i + j <= 2n, so a_i divides i+j: walk the multiples of a_i.
// Values are distinct, so sum over i of (2n / a_i) is O(n log n).
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int s = a[i]; s <= 2 * n; s += a[i]) // s plays the role of i + j
        {
            int j = s - i;
            if (j <= i || j > n)
                continue;
            if ((ll)a[i] * a[j] == s)
                ans++;
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
