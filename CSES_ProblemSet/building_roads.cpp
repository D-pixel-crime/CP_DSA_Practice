#include <bits/stdc++.h>
using namespace std;

int findPar(vector<int> &par, int n)
{
    if (n == par[n])
    {
        return n;
    }
    return par[n] = findPar(par, par[n]);
}

void dsu(vector<int> &par, vector<int> &s, int a, int b)
{
    int ua = findPar(par, a), ub = findPar(par, b);
    if (ua == ub)
    {
        return;
    }

    if (s[ua] >= s[ub])
    {
        s[ua] += s[ub];
        par[ub] = ua;
    }
    else
    {
        s[ub] += s[ua];
        par[ua] = par[ub];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> par(n + 1), s(n + 1, 1);
    iota(par.begin(), par.end(), 0);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu(par, s, a, b);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == i)
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() - 1 << "\n";
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i - 1] << " " << ans[i] << "\n";
    }

    return 0;
}