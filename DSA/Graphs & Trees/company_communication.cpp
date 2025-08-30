#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> graph;
    unordered_map<int, vector<int>> lang;

    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0, temp; j < k; j++)
        {
            cin >> temp;
            lang[temp].push_back(i);
        }
    }

    for (auto &i : lang)
    {
        auto arr = i.second;
        int j = 0, k = 1;
        for (; k < arr.size(); k++)
        { 
            graph[arr[j]].push_back(arr[k]);
            graph[arr[k]].push_back(arr[j]);
        }
    }

    lang.clear();
    unordered_map<int, bool> visited;

    function<void(int)> dfs = [&](int node)
    {
        // visited[node] = true;
        for (auto &j : graph[node])
        {
            if (!visited.count(j))
            {
                visited[j] = true;
                dfs(j);
            }
        }
    };
    visited[1] = true;
    dfs(1);

    cout << (visited.size() == n ? "YES\n" : "NO\n");

    return 0;
}