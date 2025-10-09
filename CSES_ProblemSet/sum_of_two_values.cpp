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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll x;
    cin >> n >> x;

    vector<pair<ll, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(all(arr), [](const auto &a, const auto &b)
         { return a.first < b.first; });

    int i = 0, j = n - 1;
    while (i < j)
    {
        ll sum = arr[i].first + arr[j].first;
        if (sum == x)
        {
            cout << min(arr[i].second + 1, arr[j].second + 1) << " " << max(arr[i].second + 1, arr[j].second + 1) << endl;
            return 0;
        }
        else if (sum < x)
        {
            i++;
        }
        else
            j--;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}