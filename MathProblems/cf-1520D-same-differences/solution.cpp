// CF 1520D - Same Differences
// a_j - a_i == j - i  <=>  a_j - j == a_i - i. Group by the key, sum C(c,2).
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    map<int, ll> freq;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int key = a - i;
        ans += freq[key]; // pairs with every earlier element sharing the key
        freq[key]++;
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
