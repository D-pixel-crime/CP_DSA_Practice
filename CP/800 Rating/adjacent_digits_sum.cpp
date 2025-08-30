#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int x, y;
    cin >> x >> y;

    if (((x - y + 1) % 9 == 0) && ((x - y + 1) / 9 >= 0))
    {
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
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