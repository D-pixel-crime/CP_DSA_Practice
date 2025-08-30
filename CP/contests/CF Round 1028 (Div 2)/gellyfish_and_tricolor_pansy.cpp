#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (min(a, c) >= min(b, d))
    {
        cout << "Gellyfish\n";
    }
    else
        cout << "Flower\n";
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