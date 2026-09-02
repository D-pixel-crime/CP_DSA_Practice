#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '.' && !vis[i][j])
            {
                vis[i][j] = true;
                ans++;
                q.push({i, j});
                while (!q.empty())
                {
                    auto [a, b] = q.front();
                    q.pop();

                    for (auto &[x, y] : dir)
                    {
                        int na = x + a, nb = y + b;
                        if (na >= 0 && na < n && nb >= 0 && nb < m && g[na][nb] == '.' && !vis[na][nb])
                        {
                            vis[na][nb] = true;
                            q.push({na, nb});
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}