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
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i + 1] == 0)
        {
            cout << -1 << endl;
            return;
        }

        if (arr[i] >= arr[i + 1])
        {
            while (arr[i] >= arr[i + 1])
            {
                arr[i] >>= 1;
                ans++;
            }
        }
    }

    cout << ans << endl;
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