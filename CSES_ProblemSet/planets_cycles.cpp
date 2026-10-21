#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> anc;
vector<uint8_t> vis;
vector<int> len;

void dfs(int node)
{
    if (vis[node] == 2)
    {
        return;
    }

    vis[node] = 1;

    if (vis[anc[node][0]] == 0)
    {
        dfs(anc[node][0]);
    }

    if (vis[anc[node][0]] == 1)
    {
        int curr = anc[anc[node][0]][0];
        int c = 1;
        for (; curr != anc[node][0]; curr = anc[curr][0])
        {
            c++;
        }

        curr = anc[node][0];
        do
        {
            len[curr] = c;
            vis[curr] = 2;
            curr = anc[curr][0];
        } while (curr != anc[node][0]);
    }

    if (vis[node] != 2)
    {
        len[node] = len[anc[node][0]] + 1;
    }
    vis[node] = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    anc.assign(n + 1, vector<int>(31, -1));
    vis.assign(n + 1, 0);
    len.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> anc[i][0];
    }

    for (int d = 1; d <= 30; d++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (anc[i][d - 1] == -1)
            {
                anc[i][d] = -1;
                break;
            }

            anc[i][d] = anc[anc[i][d - 1]][d - 1];
            if (anc[i][d] == -1)
            {
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << len[i] << " ";
    }

    return 0;
}