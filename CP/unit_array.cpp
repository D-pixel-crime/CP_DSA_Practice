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
        int countNeg = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp == -1)
                countNeg++;
        }

        int half = n / 2;

        if (half & 1)
        {
            half--;
        }

        if (countNeg > half)
            cout << abs(countNeg - half) << endl;
        else
        {
            if (countNeg & 1)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }

    return 0;
}