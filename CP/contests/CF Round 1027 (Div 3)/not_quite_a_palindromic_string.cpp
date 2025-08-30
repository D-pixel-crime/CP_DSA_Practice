#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            one++;
        else
            zero++;
    }

    int needed = (n - (2 * k)) / 2;
    if (zero - needed < 0 || one - needed < 0)
    {
        cout << "NO\n";
        return;
    }

    if (((zero - needed) & 1) || ((one - needed) & 1))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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