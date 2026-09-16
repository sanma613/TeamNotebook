#include <bits/stdc++.h>
using namespace std;

// Este codigo puede sufrir de stack overflow para matrices muy grandes
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int i, int j, int n, int m, const vector<string> &grid, vector<vector<bool>> &visited)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;
    if (grid[i][j] == '#' || visited[i][j])
        return;

    visited[i][j] = true;

    for (int d = 0; d < 4; d++)
    {
        dfs(i + dx[d], j + dy[d], n, m, grid, visited);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j, n, m, grid, visited);
                cnt++; // Encontramos un componente conexo (habitación)
            }
        }
    }

    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}