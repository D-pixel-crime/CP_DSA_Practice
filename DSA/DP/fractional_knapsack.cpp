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

    double n, c;
    cin >> n >> c;

    vector<vector<double>> arr(n, vector<double>(2));
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1];

    sort(all(arr), [](const auto &a, const auto &b)
         { return a[0] / a[1] > b[0] / b[1]; });

    double ans = 0;

    int i = 0;
    while (i < n && c)
    {
        if (arr[i][1] <= c)
        {
            c -= arr[i][1];
            ans += arr[i][0];
        }
        else
        {
            ans += ((arr[i][0] / arr[i][1]) * c);
            c = 0;
        }
        i++;
    }

    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}