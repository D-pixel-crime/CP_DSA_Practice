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

    int n, c;
    cin >> n >> c;

    vector<vector<ll>> arr(n, vector<ll>(2));
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1];

    vector<ll> prev(c + 1);
    for (int i = 0; i < n; i++)
    {
        vector<ll> curr(c + 1);
        for (int j = 0; j <= c; j++)
        {
            curr[j] = prev[j];
            if (j >= arr[i][0])
            {
                curr[j] = max(curr[j], arr[i][1] + prev[j - arr[i][0]]);
            }
        }
        prev = curr;
    }

    cout << prev[c] << endl;

    return 0;
}