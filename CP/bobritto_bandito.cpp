#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, m, l, r;
    cin >> n >> m >> l >> r;

    int diff = n - m;

    if (diff <= r)
    {
        cout << l << " " << r - diff << endl;
        return;
    }
    cout << l + (diff - r) << " " << 0 << endl;
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