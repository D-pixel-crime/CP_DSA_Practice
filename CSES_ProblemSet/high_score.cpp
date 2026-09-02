#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = LLONG_MIN / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, ll>> edges;
    vector<vector<pair<int, ll>>> g(n + 1);

    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
        g[a].push_back({b, c});
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    vector<bool> vis(n + 1, false);
    queue<int> q;

    for (int k = 1; k <= n; k++)
    {
        for (auto &[i, j, c] : edges)
        {
            if (dist[i] != INF && dist[i] > dist[j] - c)
            {
                if (k == n)
                {
                    q.push(j);
                    vis[j] = true;
                }
                else
                {
                    dist[j] = dist[i] + c;
                }
            }
        }
    }

    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        if (i == n)
        {
            cout << -1 << "\n";
            return 0;
        }

        for (auto &[j, c] : g[i])
        {
            if (!vis[j])
            {
                vis[j] = true;
                q.push(j);
            }
        }
    }

    cout << dist[n] << "\n";

    return 0;
}