#include <bits/stdc++.h>
using namespace std;

// Arreglos de dirección constantes
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char letters[] = {'D', 'U', 'R', 'L'};

bool dfs(int r, int c, int end_r, int end_c, int n, int m,
         const vector<string> &grid, vector<vector<bool>> &visited, string &path)
{
    if (r == end_r && c == end_c)
        return true;

    visited[r][c] = true;

    for (int d = 0; d < 4; d++)
    {
        int nr = r + dx[d];
        int nc = c + dy[d];

        // Validar límites y paredes ANTES de llamar a la recursión
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && !visited[nr][nc])
        {
            path.push_back(letters[d]);

            if (dfs(nr, nc, end_r, end_c, n, m, grid, visited, path))
            {
                return true;
            }

            path.pop_back(); // Backtracking
        }
    }

    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    int start_r = -1, start_c = -1, end_r = -1, end_c = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                start_r = i;
                start_c = j;
            }
            else if (grid[i][j] == 'B')
            {
                end_r = i;
                end_c = j;
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    string path = "";

    if (dfs(start_r, start_c, end_r, end_c, n, m, grid, visited, path))
    {
        cout << "YES\n"
             << path.size() << "\n"
             << path << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    // Optimización de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}