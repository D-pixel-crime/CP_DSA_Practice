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
        int arrayXOR = 0, maxArr = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arrayXOR ^= temp;
            maxArr = max(maxArr, temp);
        }

        if (n & 1)
        {
            cout << arrayXOR << "\n";
        }
        else
        {
            if (!arrayXOR)
            {
                cout << maxArr << "\n";
            }
            else
                cout << -1 << "\n";
        }
    }

    return 0;
}