#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;

    if ((2 * b - c) % a == 0 && (2 * b - c) / a > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if ((c + a) % (2*b) == 0 && (c + a) / (2*b) > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if ((2 * b - a) % c == 0 && (2 * b - a) / c > 0)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO\n";
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