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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n == 1)
    {
        cout << (arr[0] != 0 ? 1 : 0) << endl;
        return;
    }

    int ans = 0, i = 0;
    while (i < n)
    {
        while (i < n && arr[i] == 0)
            i++;
        if (i >= n)
            break;
        ans++;
        while (i < n && arr[i] != 0)
            i++;
    }

    cout << min(ans, 2) << endl;
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