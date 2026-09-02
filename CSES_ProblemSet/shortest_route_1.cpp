#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> g(n + 1);
    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<ll> dist(n + 1, LLONG_MAX / 2);
    dist[1] = 0;
    pq.push({0LL, 1});

    while (!pq.empty())
    {
        auto [d, i] = pq.top();
        pq.pop();

        if (d > dist[i])
        {
            continue;
        }

        for (auto &[j, c] : g[i])
        {
            ll nd = d + c;
            if (dist[j] > nd)
            {
                dist[j] = nd;
                pq.push({nd, j});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    cout << "\n";

    return 0;
}