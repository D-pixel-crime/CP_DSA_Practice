#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <format>
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
    queue<pair<int, int>> q;
    vector<vector<int>> steps(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> taken(n, vector<char>(m, '.'));
    vector<vector<int>> closestMonster(n, vector<int>(m, INT_MAX));
    int si, sj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                si = i, sj = j;
            }
            else if (g[i][j] == 'M')
            {
                q.push({i, j});
                vis[i][j] = true;
                closestMonster[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        for (auto &[a, b, c] : dir)
        {
            int ni = i + a, nj = j + b;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] != '#' && !vis[ni][nj])
            {
                closestMonster[ni][nj] = closestMonster[i][j] + 1;
                vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }

    for (auto &i : vis)
    {
        fill(i.begin(), i.end(), false);
    }

    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        if (!i || !j || i == n - 1 || j == m - 1)
        {
            string ans = "";
            while (i != -1 && j != -1)
            {
                ans.push_back(taken[i][j]);
                auto &p = par[i][j];
                i = p.first, j = p.second;
            }

            ans.pop_back();
            reverse(ans.begin(), ans.end());

            cout << format("YES\n{}\n{}\n", ans.size(), ans);

            return 0;
        }

        for (auto &[a, b, c] : dir)
        {
            int ni = a + i, nj = j + b;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] != '#' && !vis[ni][nj] && closestMonster[ni][nj] > steps[i][j] + 1)
            {
                vis[ni][nj] = true;
                par[ni][nj] = {i, j};
                steps[ni][nj] = steps[i][j] + 1;
                taken[ni][nj] = c;
                q.push({ni, nj});
            }
        }
    }

    cout << "NO\n";

    return 0;
}