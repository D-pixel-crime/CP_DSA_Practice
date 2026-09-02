#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <format>
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

    vector<int> par(n + 1, -1);
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        if (node == n)
        {
            vector<int> ans;
            while (node != -1)
            {
                ans.push_back(node);
                node = par[node];
            }

            cout << ans.size() << "\n";
            while (!ans.empty())
            {
                cout << ans.back() << " ";
                ans.pop_back();
            }

            return 0;
        }

        for (auto &j : g[node])
        {
            if (!vis[j])
            {
                vis[j] = true;
                par[j] = node;
                q.push(j);
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}