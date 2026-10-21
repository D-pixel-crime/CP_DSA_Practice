#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll countHyphen = count(all(s), '-');

    cout << ((countHyphen / 2) * (ll)ceil(countHyphen / 2.0) * (n - countHyphen)) << endl;
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