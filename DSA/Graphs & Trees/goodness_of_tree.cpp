#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define concatenateTwoArrays(a, b) a.insert(a.end(), all(b))

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

    unordered_map<int, vector<pair<int, ll>>> graph;
    unordered_map<int, int> category;
    for (int i = 0; i < n; i++)
    {
        cin >> category[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        ll dist;
        cin >> u >> v >> dist;
        graph[u].push_back({v, dist});
        graph[v].push_back({u, dist});
    }

    unordered_map<int, ll> depth;
    ll ans = 0;

    function<vector<int>(int, int, ll)> dfs = [&](int node, int par, ll d)
    {
        vector<int> children = {node};
        depth[node] = d;

        for (auto [j, dist] : graph[node])
        {
            if (j != par)
            {
                vector<int> temp = dfs(j, node, (d + dist) % mod);

                for (auto &a : children)
                {
                    for (auto &b : temp)
                    {
                        if (category[a] == category[b])
                        {
                            ll distA = (depth[a] - depth[node] + mod) % mod;
                            ll distB = (depth[b] - depth[node] + mod) % mod;

                            ans = (ans + ((distA + distB) % mod)) % mod;
                        }
                    }
                }

                concatenateTwoArrays(children, temp);
            }
        }

        return children;
    };

    dfs(0, -1, 0LL);

    cout << ans << endl;

    return 0;
}