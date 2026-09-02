#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using node = pair<ll, int>;

constexpr ll INF = LLONG_MAX / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> g(n + 1);
    int a, b;
    ll c;
    while (m--)
    {
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }

    vector<multiset<ll>> dist(n + 1);
    priority_queue<node, vector<node>, greater<>> pq;
    pq.push({0LL, 1});
    dist[1].insert(0LL);

    while (!pq.empty())
    {
        auto [d, i] = pq.top();
        pq.pop();

        if (d > *dist[i].rbegin())
        {
            continue;
        }

        for (auto &[j, c] : g[i])
        {
            ll nd = d + c;
            if (dist[j].size() < k || nd < *dist[j].rbegin())
            {
                dist[j].insert(nd);
                if (dist[j].size() > k)
                {
                    dist[j].erase(prev(dist[j].end()));
                }
                pq.push({nd, j});
            }
        }
    }

    for (auto &i : dist[n])
    {
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}