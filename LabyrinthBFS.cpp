#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

// Constantes globales de movimiento (Abajo, Arriba, Derecha, Izquierda)
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char letters[] = {'D', 'U', 'R', 'L'};

inline bool is_valid(int r, int c, int n, int m)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    int start_r = -1, start_c = -1;
    int end_r = -1, end_c = -1;

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

    // Matriz para guardar la dirección (0..3) que nos llevó a cada celda
    vector<vector<int>> parent_dir(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pii> q;

    q.push({start_r, start_c});
    visited[start_r][start_c] = true;
    bool reached = false;

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        if (r == end_r && c == end_c)
        {
            reached = true;
            break;
        }

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (is_valid(nr, nc, n, m) && grid[nr][nc] != '#' && !visited[nr][nc])
            {
                visited[nr][nc] = true;
                parent_dir[nr][nc] = d;
                q.push({nr, nc});
            }
        }
    }

    if (!reached)
    {
        cout << "NO\n";
        return;
    }

    // --- RECONSTRUCCIÓN DEL CAMINO ---
    string path = "";
    int curr_r = end_r;
    int curr_c = end_c;

    while (curr_r != start_r || curr_c != start_c)
    {
        int d = parent_dir[curr_r][curr_c];
        path.push_back(letters[d]);

        // Revertimos el paso restando las coordenadas
        curr_r -= dx[d];
        curr_c -= dy[d];
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
}

int main()
{
    // Optimización de I/O para evitar TLE en competiciones
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}