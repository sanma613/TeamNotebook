// CF 600B - Queries about less or equal elements
// Sort a; count of elements <= x is upper_bound(x) - begin().
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    for (int j = 0; j < m; j++)
    {
        int x;
        cin >> x;
        cout << (upper_bound(a.begin(), a.end(), x) - a.begin()) << " \n"[j == m - 1];
    }
    return 0;
}
