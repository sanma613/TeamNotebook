// CF 1324D - Pair of Topics
// a_i+a_j > b_i+b_j  <=>  c_i + c_j > 0 with c = a - b. Sort, then two pointers.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> c(n); // ll: c_l + c_r reaches 2e9 and would overflow int
    for (ll &x : c)
        cin >> x;
    for (ll &x : c)
    {
        ll b;
        cin >> b;
        x -= b;
    }
    sort(c.begin(), c.end());

    ll ans = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (c[l] + c[r] > 0)
        {
            ans += r - l; // c[r] pairs with every index in [l, r-1]
            r--;
        }
        else
            l++;
    }
    cout << ans << '\n';
    return 0;
}
