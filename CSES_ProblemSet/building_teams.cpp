#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    vector<int> col(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            col[i] = 0;
            while (!q.empty())
            {
                auto node = q.front();
                q.pop();

                for (auto &j : g[node])
                {
                    if (col[j] != -1 && col[j] == col[node])
                    {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                    if (!vis[j])
                    {
                        col[j] = !col[node];
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << col[i] + 1 << " ";
    }

    cout << "\n";

    return 0;
}