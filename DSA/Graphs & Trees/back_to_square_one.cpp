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

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> graph;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    set<int> green, blue, red; // green -> unexplored, blue -> currently exploring, red -> explored
    for (int i = 0; i < n; i++)
    {
        green.insert(i);
    }

    function<bool(int)> dfs = [&](int node)
    {
        if (!graph.count(node))
        {
            green.erase(node);
            red.insert(node);
            return true;
        }

        green.erase(node);
        blue.insert(node);

        bool ans = true;
        for (auto j : graph[node])
        {
            if (blue.count(j))
            {
                return false;
            }
            else
            {
                if (green.count(j))
                {
                    ans = ans && dfs(j);
                }
            }
        }

        blue.erase(node);
        red.insert(node);
        return ans;
    };

    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (red.size() == n)
        {
            break;
        }
        else
        {
            ans = ans && dfs(i);
        }
    }

    cout << (ans ? "YES\n" : "NO\n");

    return 0;
}