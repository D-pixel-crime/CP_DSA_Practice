#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &g, vector<bool> &vis, int i)
{
    queue<int> q;
    q.push(i);
    vis[i] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &j : g[node])
        {
            if (!vis[j])
            {
                q.push(j);
                vis[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> fg(n + 1);
    vector<vector<int>> rg(n + 1);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        fg[a].push_back(b);
        rg[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    bfs(fg, vis, 1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO\n"
                 << 1 << " " << i << "\n";
            return 0;
        }
    }

    fill(vis.begin(), vis.end(), false);
    bfs(rg, vis, 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO\n"
                 << i << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}