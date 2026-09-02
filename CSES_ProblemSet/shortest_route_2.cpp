#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = LLONG_MAX / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 1; k <= n; k++)
    {
        dist[k][k] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << "\n";
    }

    return 0;
}