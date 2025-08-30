#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    queue<pair<int, int>> q;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'i')
            {
                q.push({i, j});
            }
        }
    }

    set<pair<int, int>> visited;

    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            auto [i, j] = q.front();
            q.pop();

            if (grid[i][j] == 'h')
            {
                if (curr <= k)
                {
                    cout << "YES\n";
                }
                else
                    cout << "NO\n";

                return 0;
            }

            for (auto [a, b] : dir)
            {
                int ni = a + i, nj = b + j;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] != '#' && !visited.count(make_pair(ni, nj)))
                {
                    visited.insert({ni, nj});
                    q.push({ni, nj});
                }
            }
        }
        curr++;
    }

    cout << "NO\n";

    return 0;
}