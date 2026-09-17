#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n;

    vector<string> products(n);
    vector<vector<string>> recipes(n);
    vector<int> in_degree(n);
    unordered_map<string, vector<int>> adj;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> products[i] >> t;

        in_degree[i] += t;

        for (int j = 0; j < t; j++)
        {
            string rcp;
            cin >> rcp;

            recipes[i].push_back(rcp);

            adj[rcp].push_back(i);
        }
    }

    cin >> k;
    queue<string> q;

    for (int i = 0; i < k; i++)
    {
        string raw;
        cin >> raw;

        q.push(raw);
    }

    while (!q.empty())
    {
        string raw = q.front();
        q.pop();

        for (int i : adj[raw])
        {
            in_degree[i]--;
            if (in_degree[i] == 0)
            {
                q.push(products[i]);
            }
        }
    }

    vector<string> completed;

    for (int i = 0; i < n; i++)
    {
        if (in_degree[i] == 0)
        {
            completed.push_back(products[i]);
        }
    }

    cout << completed.size() << '\n';
    for (int i = 0; i < (int)completed.size(); i++)
    {
        cout << completed[i] << (i == (int)completed.size() - 1 ? "\n" : " ");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}