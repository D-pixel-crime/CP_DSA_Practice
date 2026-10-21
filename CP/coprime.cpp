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

    vector<int> arr(1001, -1);
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        arr[temp] = i + 1;
    }

    int ans = -1;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            if (arr[i] != -1 && arr[j] != -1 && __gcd(i, j) == 1)
            {
                ans = max(ans, arr[i] + arr[j]);
            }
        }
    }

    cout << ans << endl;
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