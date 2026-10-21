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

        sort(arr.begin(), arr.end(), greater<int>());
        if (arr[0] == arr[n - 1])
        {
            cout << "No" << "\n";
            continue;
        }

        int i = 0, j = n - 1;
        vector<int> ans;
        while (i < j)
        {
            ans.push_back(arr[i++]), ans.push_back(arr[j--]);
        }

        if(n & 1)ans.push_back(arr[i]);

        cout << "Yes" << "\n";

        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}