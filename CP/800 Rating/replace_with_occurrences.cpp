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

    int size = 0;
    vector<int> arr(n);
    set<int> count;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (!count.count(arr[i]))
        {
            size += arr[i];
            count.insert(arr[i]);
        }
    }

    if (size <= n)
    {
        for (auto &i : arr)
        {
            cout << i << " ";
        }
    }
    else
        cout << -1;

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