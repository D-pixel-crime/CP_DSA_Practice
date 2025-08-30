#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> graph;
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start, end;
    cin >> start >> end;

    int ans = 0;
    set<int> visited;

    queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int node = q.front();
            q.pop();
            if (node == end)
            {
                cout << ans << endl;
                return 0;
            }

            for (auto neighbour : graph[node])
            {
                if (!visited.count(neighbour))
                {
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        ans++;
    }

    cout << 0 << endl;

    return 0;
}