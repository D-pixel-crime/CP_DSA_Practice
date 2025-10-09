#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

void solve()
{
    ll a, b;
    cin >> a >> b;

    if (!(a & 1) && (b & 1))
    {
        cout << -1 << endl;
        return;
    }
    if (!(a & 1) && !(b & 1))
    {
        cout << (a * (b / 2)) + 2 << endl;
        return;
    }
    if ((a & 1))
    {
        if (b & 1)
        {
            cout << (a * b) + 1 << endl;
            return;
        }
        if (b % 4 != 0)
        {
            cout << -1 << endl;
            return;
        }
        cout << (a * (b / 2)) + 2 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}