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

    int n;
    cin >> n;
    int m;
    cin >> m;

    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> inDegree;

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!inDegree.count(i))
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (auto j : graph[node])
            {
                if (inDegree[j] > 0)
                {
                    inDegree[j]--;
                    if (inDegree[j] == 0)
                    {
                        q.push(j);
                    }
                }
            }
        }
    }

    return 0;
}