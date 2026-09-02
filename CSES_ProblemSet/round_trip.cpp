#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> s;
vector<int> par;

bool solve(int node)
{
    for (auto &j : g[node])
    {
        if (vis[j] && s[node] - s[j] >= 2)
        {
            cout << abs(s[node] - s[j]) + 2 << "\n";
            cout << j << " ";
            while (node != j)
            {
                cout << node << " ";
                node = par[node];
            }
            cout << node << " ";

            return true;
        }
        else if (!vis[j])
        {
            par[j] = node;
            vis[j] = true;
            s[j] = s[node] + 1;

            if (solve(j))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g = vector<vector<int>>(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis = vector<bool>(n + 1, false);
    s = vector<int>(n + 1, 0);
    par = vector<int>(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            s[i] = 1;
            vis[i] = true;
            if (solve(i))
            {
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}