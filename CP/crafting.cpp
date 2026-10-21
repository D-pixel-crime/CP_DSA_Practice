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

    int count = 0;
    ll diff = LLONG_MAX, req = 0;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        arr[i] = {temp, 0};
    }
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        arr[i].second = temp;
    }

    for (auto [a, b] : arr)
    {
        if (a < b)
        {
            count++;
            req = b - a;
        }
        else
        {
            diff = min(diff, a - b);
        }
    }

    if (count == 0)
    {
        cout << "YES\n";
        return;
    }
    else if (count > 1)
    {
        cout << "NO\n";
        return;
    }

    cout << (req <= diff ? "YES\n" : "NO\n");
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