#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(all(arr));

    int i = 0;
    int ans = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n && arr[j] - arr[j - 1] <= k)
            j++;

        ans = max(ans, j - i);
        i = j;
    }

    cout << n - ans << endl;
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