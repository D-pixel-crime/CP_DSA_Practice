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
    int n, s;
    cin >> n >> s;

    vector<int> arr(3);
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        arr[temp]++;
    }

    int sum = arr[1] + 2 * arr[2];
    if (sum == s || sum + 2 <= s)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < arr[0]; i++)
        cout << 0 << " ";
    for (int i = 0; i < arr[2]; i++)
        cout << 2 << " ";
    for (int i = 0; i < arr[1]; i++)
        cout << 1 << " ";

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