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

    int n, m, k;
    cin >> n >> m >> k;

    unordered_map<int, vector<int>> graph;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    set<vector<int>> restricted;
    for (int i = 0, a, b, c; i < k; i++)
    {
        cin >> a >> b >> c;
        restricted.insert({a, b, c});
    }

    set<pair<int, int>> visited;
    queue<tuple<vector<int>, int>> q;
    q.push({{1}, 1});

    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            auto [order, node] = q.front();
            q.pop();

            if (node == n)
            {
                cout << order.size() - 1 << endl;
                for (auto i : order)
                {
                    cout << i << " ";
                }
                return 0;
            }

            for (auto j : graph[node])
            {
                if (order.size() >= 2)
                {
                    if (!restricted.count({order[order.size() - 2], order[order.size() - 1], j}) && !visited.count({node, j}))
                    {
                        order.push_back(j);
                        visited.insert({node, j});
                        q.push({order, j});
                        order.pop_back();
                    }
                }
                else
                {
                    if (!visited.count({node, j}))
                    {
                        order.push_back(j);
                        visited.insert({node, j});
                        q.push({order, j});
                        order.pop_back();
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}