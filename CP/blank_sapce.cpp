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
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = 0;
        int i = 0;
        while (i < n)
        {

            int j = i;
            while (j < n && arr[j] == arr[i])
                j++;

            if (arr[i] == 0)
                ans = max(ans, j - i);
            i = j;
        }

        cout << ans << "\n";
    }

    return 0;
}