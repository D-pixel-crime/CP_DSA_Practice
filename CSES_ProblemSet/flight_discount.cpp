#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> node;

constexpr ll INF = LLONG_MAX / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> g(2 * n + 2);
    int a, b;
    ll c;
    while (m--)
    {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[a + n].push_back({b + n, c});
        g[a].push_back({b + n, c / 2});
    }

    vector<ll> dist(2 * n + 1, INF);
    priority_queue<node, vector<node>, greater<>> pq;

    pq.push({0LL, 1});
    dist[1] = dist[n + 1] = 0;

    ll ans = INF;

    while (!pq.empty())
    {
        auto [d, i] = pq.top();
        pq.pop();

        if (i == n || i == 2 * n)
        {
            ans = d;
            break;
        }

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

    cout << ans << "\n";

    return 0;
}