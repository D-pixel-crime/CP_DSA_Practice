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
        int countOdd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] & 1)
                countOdd++;
        }

        if (!(countOdd & 1))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }

    return 0;
}