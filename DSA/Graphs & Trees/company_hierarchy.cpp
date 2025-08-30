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
    for (int i = 2, j; i <= n; i++)
    {
        cin >> j;
        graph[j].push_back(i);
    }

    vector<int> count(n + 1);

    function<int(int, int)> dfs = [&](int node, int par)
    {
        if (!graph.count(node))
        {
            return 1;
        }

        int ans = 0;
        for (auto j : graph[node])
        {
            if (j != par)
            {
                ans += dfs(j, node);
            }
        }

        count[node] = ans;
        return ans + 1;
    };

    dfs(1, -1);

    for (int i = 1; i <= n; i++)
    {
        cout << count[i] << " ";
    }

    return 0;
}