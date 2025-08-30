#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i <= b; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> graph;
    set<int> visited;

    rep(i, 1, n)
    {
        int isHospital;
        cin >> isHospital;
        if (isHospital)
        {
            graph[n + 1].push_back(i);
        }
    }

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    q.push(n + 1);

    vector<int> dist(n + 2, -1);

    int curr = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int node = q.front();
            q.pop();

            dist[node] = curr - 1;

            for (auto j : graph[node])
            {
                if (!visited.count(j))
                {
                    visited.insert(j);
                    q.push(j);
                }
            }
        }
        curr++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == -1)
        {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans << endl;

    return 0;
}