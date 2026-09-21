// CF 1931D - Divisible Pairs
// Key each element by (a%x, a%y); a_j pairs with earlier keys ((x-a_j%x)%x, a_j%y).
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    map<pair<int, int>, int> seen;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int rx = a % x, ry = a % y;
        auto it = seen.find({(x - rx) % x, ry}); // outer %x: rx==0 -> complement 0
        if (it != seen.end())
            ans += it->second;
        seen[{rx, ry}]++; // insert after querying => counts i < j once
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
