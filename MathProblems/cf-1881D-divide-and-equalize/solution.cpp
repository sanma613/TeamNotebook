// CF 1881D - Divide and Equalize
// The product is invariant; all equal <=> every prime's total exponent divisible by n.
#include <bits/stdc++.h>
using namespace std;

const int LIM = 1000001;
int spf[LIM]; // smallest prime factor

void build_spf()
{
    for (int i = 2; i < LIM; i++)
        if (!spf[i])
            for (int j = i; j < LIM; j += i)
                if (!spf[j])
                    spf[j] = i;
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> exp_total;
    exp_total.reserve(4 * n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (x > 1) // a_i == 1 skips this entirely
        {
            int p = spf[x];
            while (x % p == 0)
            {
                x /= p;
                exp_total[p]++;
            }
        }
    }

    bool ok = true;
    for (auto &[p, e] : exp_total)
        if (e % n)
            ok = false;

    cout << (ok ? "YES" : "NO") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    build_spf(); // once, never per testcase
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
