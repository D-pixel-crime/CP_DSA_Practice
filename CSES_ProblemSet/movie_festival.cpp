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
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(all(arr), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    int ans = 0;
    int i = 0, last = -1;
    while (i < n)
    {
        if (arr[i].first >= last)
        {
            ans++;
            last = arr[i].second;
        }
        i++;
    }

    cout << ans << endl;

    return 0;
}