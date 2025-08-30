#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int, vector<int>> graph;
    int root = 1, m = -1;
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto &i : graph)
    {
        if (i.second.size() > m)
        {
            root = i.first;
            m = i.second.size();
        }
    }

    int ans = 0;
    function<int(int, int)> dfs = [&](int node, int par)
    {
        if (graph[node].size() == 1 && node != 1)
        {
            return 1;
        }

        int m1 = INT_MIN, m2 = m1;
        for (auto j : graph[node])
        {
            if (j != par)
            {
                int d = dfs(j, node);
                if (d > m1)
                {
                    m2 = m1, m1 = d;
                }
                else if (d > m2)
                {
                    m2 = d;
                }
            }
        }

        if (m2 != INT_MIN && m1 != INT_MIN)
        {
            ans = max(ans, m1 + m2);
        }
        else
            ans = max(ans, m1);

        return m1 + 1;
    };

    dfs(root, 0);

    cout << ans << endl;

    return 0;
}