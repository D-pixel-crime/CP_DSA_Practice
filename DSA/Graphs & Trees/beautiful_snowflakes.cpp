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

    int n, m;
    cin >> n >> m;

    unordered_map<int, int> isThere;
    vector<vector<int>> graph(n + 1);
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        bool isBeaut = true;
        for (auto neighbour : graph[i])
        {
            if (graph[neighbour].size() != 1)
            {
                isBeaut = false;
                break;
            }
        }
        if (isBeaut)
        {
            isThere[graph[i].size()]++;
        }
    }

    int ans = 0;
    for (auto &i : isThere)
    {
        if (i.second == 1)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}