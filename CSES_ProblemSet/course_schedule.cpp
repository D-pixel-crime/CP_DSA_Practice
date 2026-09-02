#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1);
    int a, b;
    while (m--)
    {
        cin >> a >> b;

        g[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (!indeg[i])
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        ans.push_back(i);

        for (auto &j : g[i])
        {
            indeg[j]--;
            if (!indeg[j])
            {
                q.push(j);
            }
        }
    }

    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (auto &i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}