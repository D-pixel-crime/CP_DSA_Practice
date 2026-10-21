#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> space(n + 1, false);
    vector<int> list(m);
    for (int i = 0; i < m; i++)
        cin >> list[i];
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        space[temp] = true;
    }

    if (k < n - 1)
    {
        for (int i = 0; i < m; i++)
            cout << 0;
        cout << endl;
        return;
    }
    if (k == n)
    {
        for (int i = 0; i < m; i++)
            cout << 1;
        cout << endl;
        return;
    }

    for (auto i : list)
    {
        if (!space[i])
            cout << 1;
        else
            cout << 0;
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}