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
    int n;
    cin >> n;

    ll k;
    cin >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        if (arr[0] == k)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
        return;
    }

    sort(all(arr));

    int i = 0, j = 1;
    while (i < n && j < n)
    {
        ll temp = arr[i] + k;
        if (temp > arr[j])
        {
            j++;
        }
        else if (temp < arr[j])
        {
            i++;
        }
        else
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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