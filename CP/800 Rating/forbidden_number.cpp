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
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1)
        {
            cout << "Yes" << endl
                 << n << endl;

            for (int i = 1; i <= n; i++)
                cout << 1 << " ";
            cout << endl;
        }
        else
        {
            if (k <= 1 || n <= 1)
            {
                cout << "No" << endl;
                continue;
            }
            if (!(n & 1))
            {
                int len = n / 2;
                cout << "Yes" << endl
                     << len << endl;
                for (int i = 1; i <= len; i++)
                    cout << 2 << " ";
                cout << endl;
                continue;
            }
            if (k >= 3)
            {
                int len = n / 2;
                cout << "Yes" << endl
                     << len << endl;
                for (int i = 1; i <= len - 1; i++)
                    cout << 2 << " ";
                cout << 3 << endl;
                continue;
            }
            cout << "No" << endl;
        }
    }

    return 0;
}