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

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 1)
            arr[i]++;
        if (arr[i + 1] % arr[i] == 0)
            arr[i + 1]++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] % arr[i] == 0)
            arr[i + 1]++;
    }

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
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