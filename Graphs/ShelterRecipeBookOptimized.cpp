#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> name_to_id;
vector<string> id_to_name;

int get_id(const string &s)
{
    auto it = name_to_id.find(s);
    if (it != name_to_id.end())
        return it->second;
    int id = id_to_name.size();
    id_to_name.push_back(s);
    return name_to_id[s] = id;
}

void solve()
{
    int n, k;
    if (!(cin >> n))
        return;

    vector<int> product_ids(n);
    vector<int> in_degree;
    vector<vector<int>> adj;

    for (int i = 0; i < n; i++)
    {
        string prod;
        int t;
        cin >> prod >> t;

        int p_id = get_id(prod);
        product_ids[i] = p_id;

        if ((int)in_degree.size() <= p_id)
            in_degree.resize(p_id + 1, 0);
        in_degree[p_id] = t;

        for (int j = 0; j < t; j++)
        {
            string rcp;
            cin >> rcp;
            int r_id = get_id(rcp);

            if ((int)adj.size() <= r_id)
                adj.resize(r_id + 1);
            adj[r_id].push_back(p_id);
        }
    }

    cin >> k;
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        string raw;
        cin >> raw;
        if (name_to_id.count(raw))
        {
            q.push(name_to_id[raw]);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u < (int)adj.size())
        {
            for (int v : adj[u])
            {
                in_degree[v]--;
                if (in_degree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }

    vector<string> completed;
    for (int i = 0; i < n; i++)
    {
        int p_id = product_ids[i];
        if (in_degree[p_id] == 0)
        {
            completed.push_back(id_to_name[p_id]);
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
    solve();
    return 0;
}