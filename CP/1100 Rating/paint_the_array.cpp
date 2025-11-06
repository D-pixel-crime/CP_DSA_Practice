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

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll gcdOdd = 0, gcdEven = 0;
    for (int i = 0; i < n; i += 2)
    {
        gcdEven = __gcd(gcdEven, arr[i]);
    }
    for (int i = 1; i < n; i += 2)
    {
        gcdOdd = __gcd(gcdOdd, arr[i]);
    }

    bool isOk = true;
    for (int i = 0; i < n; i += 2)
    {
        if (arr[i] % gcdOdd == 0)
        {
            isOk = false;
            break;
        }
    }

    if (isOk)
    {
        cout << gcdOdd << endl;
        return;
    }
    isOk = true;

    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] % gcdEven == 0)
        {
            isOk = false;
            break;
        }
    }

    if (isOk)
    {
        cout << gcdEven << endl;
    }
    else
        cout << 0 << endl;
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