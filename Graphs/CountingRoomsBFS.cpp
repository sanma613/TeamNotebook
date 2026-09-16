#include <bits/stdc++.h>
// Proporciona una estructura de cola con operaciones O(1) y optimizacion en manejo de memoria
#include <queue>
using namespace std;

using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_valid(int r, int c, int n, int m) { return (r >= 0 && r < n) && (c >= 0 && c < m); };

void bfs(int start_r, int start_c, int n, int m, vector<string> &grid, vector<vector<bool>> &visited)
{
    queue<pii> q;

    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (is_valid(nr, nc, n, m) && grid[nr][nc] == '.' && !visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        };
    };
};

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
                bfs(i, j, n, m, grid, visited);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}