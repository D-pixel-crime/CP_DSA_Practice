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

    ll sum = 0;
    ll minTerm = LLONG_MAX;
    int countNeg = 0;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        if (temp < 0)
        {
            countNeg++;
        }
        sum += abs(temp);
        minTerm = min(abs(temp), minTerm);
    }

    cout << ((countNeg & 1) ? sum - (2 * minTerm) : sum) << endl;
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