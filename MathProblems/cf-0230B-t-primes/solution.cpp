// CF 230B - T-primes
// x has exactly 3 divisors  <=>  x = p^2 with p prime.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int LIM = 1000001; // sqrt(1e12) = 1e6

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> composite(LIM, false);
    composite[0] = composite[1] = true; // 0 and 1 are not prime
    for (int i = 2; (ll)i * i < LIM; i++)
        if (!composite[i])
            for (int j = i * i; j < LIM; j += i)
                composite[j] = true;

    int n;
    cin >> n;
    while (n--)
    {
        ll x;
        cin >> x;

        // Integer square root, corrected for floating point error.
        ll y = (ll)sqrtl((long double)x);
        while (y > 0 && y * y > x)
            y--;
        while ((y + 1) * (y + 1) <= x)
            y++;

        bool ok = (y * y == x) && y < LIM && !composite[y];
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
