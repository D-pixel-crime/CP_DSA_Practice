#include <bits/stdc++.h>
using namespace std;

void kosaraju(vector<vector<int>> &g, vector<bool> &vis, vector<int> &st, vector<int> &scc, int i, int cnt)
{
    scc[i] = cnt;
    for (auto &j : g[i])
    {
        if (!vis[j])
        {
            vis[j] = true;
            kosaraju(g, vis, st, scc, j, cnt);
        }
    }
    st.emplace_back(i);
}

int d = 1;
int c = 1;
vector<int> comp;
vector<int> s;

void tarjan(vector<vector<int>> &g, vector<int> &disc, vector<int> &low, vector<bool> &vis, int i)
{
    low[i] = disc[i];
    s.emplace_back(i);
    for (auto &j : g[i])
    {
        if (!disc[j])
        {
            vis[j] = true;
            disc[j] = d++;
            tarjan(g, disc, low, vis, j);

            low[i] = min(low[i], low[j]);
        }
        else if (vis[j])
        {
            low[i] = min(low[i], disc[j]);
        }
    }

    if (disc[i] == low[i])
    {
        while (!s.empty())
        {
            int x = s.back();
            vis[x] = false;
            comp[x] = c;
            s.pop_back();
            if (x == i)
            {
                break;
            }
        }
        c++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> fg(n + 1);
    vector<vector<int>> rg(n + 1);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        fg[a].push_back(b);
        rg[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    comp.assign(n + 1, 0);

    // vector<int> st, scc(n + 1, -1);

    // for (int i = 1; i <= n; i++)
    // {
    //     if (!vis[i])
    //     {
    //         vis[i] = true;
    //         kosaraju(fg, vis, st, scc, i, 0);
    //     }
    // }

    // fill(vis.begin(), vis.end(), false);

    // int cnt = 1;

    // while (st.size())
    // {
    //     if (!vis[st.back()])
    //     {
    //         vis[st.back()] = true;
    //         kosaraju(rg, vis, st, scc, st.back(), cnt++);
    //     }
    //     st.pop_back();
    // }

    // cout << cnt - 1 << "\n";

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << scc[i] << " ";
    // }

    vector<int> disc(n + 1), low(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!disc[i])
        {
            vis[i] = true;
            disc[i] = d++;
            tarjan(fg, disc, low, vis, i);
        }
    }

    cout << c - 1 << "\n";

    for (int i = 1; i <= n; i++)
    {
        cout << comp[i] << " ";
    }

    return 0;
}