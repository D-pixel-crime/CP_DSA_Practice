#include <iostream>
#include <vector>
#include <format>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

vector<tuple<int, int, char>> dir = {{0, 1, 'R'}, {1, 0, 'D'}, {0, -1, 'L'}, {-1, 0, 'U'}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> g(n, string(m, '.'));
    int si, sj, ei, ej;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                si = i, sj = j;
            }
            else if (g[i][j] == 'B')
            {
                ei = i, ej = j;
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<string> path(n, string(m, ' '));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));
    bool found = false;

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        if (g[i][j] == 'B')
        {
            found = true;
            break;
        }

        for (auto &[a, b, c] : dir)
        {
            int ni = a + i, nj = b + j;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && (g[ni][nj] == '.' || g[ni][nj] == 'B') && !vis[ni][nj])
            {
                vis[ni][nj] = true;
                par[ni][nj] = {i, j};
                path[ni][nj] = c;

                q.push({ni, nj});
            }
        }
    }

    if (!found)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";

        string ans = "";
        while (ei != si || ej != sj)
        {
            ans.push_back(path[ei][ej]);
            auto &p = par[ei][ej];
            ei = p.first, ej = p.second;
        }

        reverse(ans.begin(), ans.end());
        cout << format("{}\n{}\n", ans.size(), ans);
    }

    return 0;
}