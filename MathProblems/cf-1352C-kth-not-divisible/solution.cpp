// CF 1352C - K-th Not Divisible by n
// answer = k + (k-1)/(n-1) : each block of n integers hides exactly one multiple.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Kept for reference: the binary-search version, safe if you distrust the formula.
ll bsearch_answer(ll n, ll k)
{
    ll lo = 1, hi = 2 * k;
    while (lo < hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (mid - mid / n >= k) // survivors in [1..mid]
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << k + (k - 1) / (n - 1) << '\n';
    }
    return 0;
}
