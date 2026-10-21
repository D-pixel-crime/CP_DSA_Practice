#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int last = INT_MAX;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;

        if (x >= last)
        {
            continue;
        }

        ll temp = 1LL << x;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] % temp == 0)
            {
                arr[j] += (temp >> 1);
            }
        }
        last = min(last, x);
    }

    for (auto i : arr)
    {
        cout << i << " ";
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