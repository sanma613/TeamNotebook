#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int l = -1;
    int mask = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            l = a[i];
            mask = i;
            break;
        }
    }

    if (l == -1)
    {
        cout << -1 << '\n';
        return;
    }

    int prev = -1;
    for (int i = 0; i < n; i++)
    {

        if (i == mask || i == mask + 1)
            continue;

        if (prev != -1 && a[prev] - a[i] < 2 * l)
        {
            cout << l << " " << l << " " << a[prev] << " " << a[i] << "\n";
            return;
        }

        prev = i;
    }

    cout << -1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
