#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;

    int zeroInA = count(all(a), '0');
    int zeroInB = count(all(b), '0');

    if (zeroInA == n)
    {
        cout << "YES\n";
        return;
    }

    if (zeroInA + zeroInB < n)
    {
        cout << "NO\n";
        return;
    }

    int zCount = 0, oCount = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] == '1')
            oCount++;
        else
            zCount++;
    }

    for (int i = 1; i < n; i += 2)
    {
        if (b[i] == '1')
            oCount++;
        else
            zCount++;
    }

    if (zCount < oCount)
    {
        cout << "NO\n";
        return;
    }

    zCount = 0, oCount = 0;
    for (int i = 1; i < n; i += 2)
    {
        if (a[i] == '1')
            oCount++;
        else
            zCount++;
    }

    for (int i = 0; i < n; i += 2)
    {
        if (b[i] == '1')
            oCount++;
        else
            zCount++;
    }

    if (zCount < oCount - 1)
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