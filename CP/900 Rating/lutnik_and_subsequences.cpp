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
    int zero = 0, one = 0;
    ll temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == 0)
            zero++;

        if (temp == 1)
            one++;
    }

    cout << (1ll << zero) * one << endl;
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