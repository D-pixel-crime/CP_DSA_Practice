#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using node = tuple<ll, int, int>;

vector<int> s, par;

int findPar(int n)
{
    if (n == par[n])
    {
        return n;
    }
    return par[n] = findPar(par[n]);
}

bool dsu(int a, int b)
{
    int ua = findPar(a), ub = findPar(b);
    if (ua == ub)
    {
        return false;
    }

    if (s[ua] > s[ub])
    {
        s[ua] += s[ub];
        par[ub] = ua;
    }
    else
    {
        s[ub] += s[ua];
        par[ua] = ub;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    priority_queue<node, vector<node>, greater<>> pq;

    int a, b;
    ll c;
    while (m--)
    {
        cin >> a >> b >> c;
        pq.push({c, a, b});
    }

    s.assign(n + 1, 1);
    par.assign(n + 1, 0);
    iota(par.begin(), par.end(), 0);

    ll ans = 0LL;

    while (!pq.empty())
    {
        auto [c, a, b] = pq.top();
        pq.pop();
        if (dsu(a, b))
        {
            ans += c;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == i)
        {
            cnt++;
        }
    }

    if (cnt >= 2)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << ans << "\n";
    }

    return 0;
}