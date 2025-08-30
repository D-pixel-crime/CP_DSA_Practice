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

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int i = 0, j = n - 1;
    ll left = 0, right = 0;
    int ans = 0;

    while (i <= j)
    {
        if (i == j)
        {
            if (left < right)
            {
                left += arr[i];
                if (left == right)
                {
                    ans = n;
                }
            }
            else if (right < left)
            {
                right += arr[i];
                if (left == right)
                {
                    ans = n;
                }
            }

            break;
        }
        else
        {
            if (left == right)
            {
                left += arr[i++], right += arr[j--];
            }
            else if (left < right)
            {
                left += arr[i++];
            }
            else
                right += arr[j--];
        }

        if (left == right)
        {
            ans = (n - 1 - j) + i;
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