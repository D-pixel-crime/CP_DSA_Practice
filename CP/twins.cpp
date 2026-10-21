#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    sort(all(arr), greater<>());

    vector<int> pre(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + arr[i];

    for (int i = 0; i < n; i++)
    {
        if (pre[i] > (pre[n - 1] - pre[i]))
        {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}