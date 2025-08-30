#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> arr(n);
    vector<ll> lTOrKadane(n);
    vector<ll> rTOlKadane(n);

    cin >> arr[0];
    ll curr;
    lTOrKadane[0] = curr = arr[0];

    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        curr = max(curr + arr[i], arr[i]);
        lTOrKadane[i] = max(curr, lTOrKadane[i - 1]);
    }

    curr = rTOlKadane[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        curr = max(curr + arr[i], arr[i]);
        rTOlKadane[i] = max(rTOlKadane[i + 1], curr);
    }

    ll ans = INT_MIN;

    for (int i = 1; i < n - 1; i++)
    {
        ans = max({ans, lTOrKadane[i - 1] + rTOlKadane[i], lTOrKadane[i] + rTOlKadane[i + 1]});
    }

    cout << ans << endl;

    return 0;
}