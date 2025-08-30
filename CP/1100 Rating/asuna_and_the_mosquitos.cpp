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

    ll odd = 0, sum = 0, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        sum += temp;
        if (temp & 1)
        {
            odd++;
        }
        maxi = max(maxi, temp);
    }

    if (odd == n || odd == 0)
    {
        cout << maxi << endl;
        return;
    }

    cout << sum - odd + 1 << endl;
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