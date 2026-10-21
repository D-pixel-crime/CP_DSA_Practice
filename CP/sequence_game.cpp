#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long

int main()
{
    fastread;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
            cin >> arr[i];

        vector<ll> ans;
        ans.push_back(arr[0]);

        for (ll i = 1; i < n; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                ans.push_back(arr[i]);
            }
            ans.push_back(arr[i]);
        }

        cout << ans.size() << endl;

        for (auto i : ans)
            cout << i << " ";

        cout << endl;
    }

    return 0;
}