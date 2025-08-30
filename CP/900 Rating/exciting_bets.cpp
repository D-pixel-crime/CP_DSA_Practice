#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    ll a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }

    ll diff = abs(a - b);

    ll moves = min(a % diff, diff - (a % diff));

    cout << diff << " " << moves << endl;
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