#include <bits/stdc++.h>
using namespace std;

#define ll long long

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

        vector<ll> arr(n);
        bool isSorted = true;
        ll minDiff = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i > 0 && arr[i - 1] > arr[i])
                isSorted = false;
        }

        if (!isSorted)
        {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < n - 1; i++)
        {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        cout << (minDiff / 2) + 1 << endl;
    }

    return 0;
}