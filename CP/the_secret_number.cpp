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
    ll n;
    cin >> n;

    vector<ll> ans;
    ll e = 10;
    for (int i = 0; i < 17; i++)
    {
        ll temp = e + 1;
        if (n % temp == 0)
        {
            ans.push_back(n / temp);
        }
        e *= 10;
    }

    cout << ans.size() << endl;
    if (ans.size() == 0)
    {
        return;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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