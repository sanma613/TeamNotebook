// CF 459B - Pashmak and Flowers
// max diff = max-min; ways = cntMax*cntMin, except when all values are equal.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> b(n);
    for (int &x : b)
        cin >> x;

    int mn = *min_element(b.begin(), b.end());
    int mx = *max_element(b.begin(), b.end());

    if (mn == mx) // every pair achieves difference 0
    {
        cout << 0 << ' ' << (ll)n * (n - 1) / 2 << '\n';
        return 0;
    }

    ll cntMin = count(b.begin(), b.end(), mn);
    ll cntMax = count(b.begin(), b.end(), mx);
    cout << mx - mn << ' ' << cntMin * cntMax << '\n';
    return 0;
}
