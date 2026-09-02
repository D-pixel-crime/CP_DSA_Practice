#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> par;
vector<int> state;

bool ans = false;

void solve(int i)
{
    state[i] = 1;

    for (auto &j : g[i])
    {
        if (state[j] == 1)
        {
            ans = true;

            vector<int> ans;

            ans.push_back(j);
            while (i != j)
            {
                ans.push_back(i);
                i = par[i];
            }
            ans.push_back(j);

            cout << ans.size() << "\n";
            while (ans.size())
            {
                cout << ans.back() << " ";
                ans.pop_back();
            }
            cout << "\n";

            break;
        }
        else if (!state[j])
        {
            par[j] = i;
            solve(j);

            if (ans)
            {
                break;
            }
        }
    }

    state[i] = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    g = vector<vector<int>>(n + 1);
    par = vector<int>(n + 1, -1);
    state = vector<int>(n + 1);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!state[i])
        {
            par[i] = i;
            state[i] = 1;
            solve(i);
            if (ans)
            {
                break;
            }
        }
    }

    if (!ans)
    {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}