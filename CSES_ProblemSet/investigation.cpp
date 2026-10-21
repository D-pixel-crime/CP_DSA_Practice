#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = LLONG_MAX / 2;
constexpr ll MOD = 1e9 + 7;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> g(n + 1);
    vector<ll> dist(n + 1, INF);
    vector<ll> cnt(n + 1);
    vector<int> mini(n + 1, INT_MAX);
    vector<int> maxi(n + 1, INT_MIN);

    int a, b;
    ll c;
    while (m--)
    {
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0LL, 1});
    dist[1] = 0;
    cnt[1] = 1;
    mini[1] = 0;
    maxi[1] = 0;

    while (!pq.empty())
    {
        auto [d, i] = pq.top();
        pq.pop();

        if (i == n || d > dist[i])
        {
            continue;
        }

        for (auto &[j, c] : g[i])
        {
            ll nd = d + c;
            if (nd < dist[j])
            {
                dist[j] = nd;
                mini[j] = mini[i] + 1;
                maxi[j] = maxi[i] + 1;
                cnt[j] = cnt[i];
                pq.push({nd, j});
            }
            else if (nd == dist[j])
            {
                cnt[j] = (cnt[j] + cnt[i]) % MOD;
                mini[j] = min(mini[j], 1 + mini[i]);
                maxi[j] = max(maxi[j], 1 + maxi[i]);
            }
        }
    }

    cout << format("{} {} {} {}\n", dist[n], cnt[n], mini[n], maxi[n]);

    return 0;
}