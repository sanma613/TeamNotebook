// CF 4C - Registration System
// map<name, times requested>; the counter IS the next free suffix.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<string, int> cnt;
    while (n--)
    {
        string s;
        cin >> s;
        if (cnt[s] == 0) // note: operator[] inserts a 0 for a new key
            cout << "OK\n";
        else
            cout << s << cnt[s] << '\n';
        cnt[s]++;
    }
    return 0;
}
