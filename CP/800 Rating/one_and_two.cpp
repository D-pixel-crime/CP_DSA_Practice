#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<double> prefix(n, 1);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i == 0)
            {
                prefix[i] = (double)(log(arr[i]));
            }
            else
                prefix[i] = prefix[i - 1] + (log(arr[i]));
        }

        int ans = -1;
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(prefix[i] - (prefix[n - 1] - prefix[i])) < 1e-9)
            {
                ans = i + 1;
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}