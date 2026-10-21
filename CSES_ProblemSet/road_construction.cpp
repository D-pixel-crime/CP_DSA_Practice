#include <bits/stdc++.h>
using namespace std;

vector<int> s, par;
unordered_map<int, bool> comps;
int maxi = 1;

int findPar(int n)
{
    if (n == par[n])
    {
        return n;
    }
    par[n] = findPar(par[n]);
    comps.erase(n);
    return par[n];
}

void dsu(int a, int b)
{
    int ua = findPar(a), ub = findPar(b);
    if (ua == ub)
    {
        return;
    }

    if (s[ua] > s[ub])
    {
        par[ub] = ua;
        comps.erase(ub);
        s[ua] += s[ub];
    }
    else
    {
        s[ub] += s[ua];
        comps.erase(ua);
        par[ua] = ub;
    }

    maxi = max({maxi, s[ua], s[ub]});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    par.assign(n + 1, 0);
    s.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        comps[i] = true;
    }

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        dsu(a, b);
        cout << comps.size() << " " << maxi << "\n";
    }

    return 0;
}