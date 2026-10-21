#include <bits/stdc++.h>
using namespace std;

constexpr int LIM = 2e5 + 2;

vector<vector<int>> anc;
vector<bool> vis;
vector<int> len;

void dfs(int node)
{
    if (vis[node])
    {
        return;
    }

    vis[node] = true;
    dfs(anc[node][0]);
    len[node] = len[anc[node][0]] + 1;

    for (int d = 1; d <= 30; d++)
    {
        anc[node][d] = anc[anc[node][d - 1]][d - 1];
        if (anc[node][d] == -1)
        {
            break;
        }
    }
}

int kthAnc(int node, int k)
{
    if (k < 0)
    {
        return -1;
    }

    for (int d = 0; d <= 30; d++)
    {
        if (k & (1 << d))
        {
            node = anc[node][d];
        }
        if (node == -1)
        {
            break;
        }
    }

    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    anc = vector<vector<int>>(LIM, vector<int>(31, -1));
    vis = vector<bool>(n + 1, false);
    len = vector<int>(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> anc[i][0];
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    int a, b;
    while (q--)
    {
        cin >> a >> b;

        if (kthAnc(a, len[a] - len[b]) == b)
        {
            cout << len[a] - len[b] << "\n";
            continue;
        }

        int entry = kthAnc(a, len[a]);
        if (len[a] < len[b] && entry == b)
        {
            cout << len[a] << "\n";
            continue;
        }

        if (kthAnc(entry, len[entry] - len[b]) == b)
        {
            cout << (len[entry] - len[b]) + len[a] << "\n";
            continue;
        }

        cout << -1 << "\n";
    }

    return 0;
}