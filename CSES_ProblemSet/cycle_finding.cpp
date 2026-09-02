#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = LLONG_MAX / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> g(n + 1);
    vector<tuple<int, int, ll>> edges;
    int a, b;
    ll c;
    while (m--)
    {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        edges.push_back({a, b, c});
    }

    vector<ll> dist(n + 1, 0);
    vector<ll> par(n + 1, -1);

    int start = -1;

    for (int k = 1; k <= n; k++)
    {
        bool updated = false;

        for (auto &[i, j, c] : edges)
        {
            if (dist[i] != INF && dist[j] > dist[i] + c)
            {
                updated = true;

                if (k == n)
                {
                    start = j;
                }

                par[j] = i;
                dist[j] = dist[i] + c;
            }
        }

        if (!updated)
        {
            break;
        }
    }

    if (start == -1)
    {
        cout << "NO\n";
    }
    else
    {
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            start = par[start];
        }

        int x = start;
        do
        {
            ans.push_back(start);
            start = par[start];
        } while (start != x);

        ans.push_back(start);

        cout << "YES\n";
        while (!ans.empty())
        {
            cout << ans.back() << " ";
            ans.pop_back();
        }
    }

    return 0;
}