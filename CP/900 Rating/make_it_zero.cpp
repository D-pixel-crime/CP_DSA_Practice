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
        int allXor = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            allXor ^= temp;
        }

        if (allXor == 0)
        {
            cout << 1 << "\n"
                 << 1 << " " << n << endl;
            continue;
        }

        if (!(n & 1))
        {
            cout << 2 << "\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << n << endl;
        }
        else
        {
            cout << 4 << "\n";
            cout << 1 << " " << n - 1 << "\n"
                 << 1 << " " << n - 1 << "\n";
            cout << n - 1 << " " << n << "\n"
                 << n - 1 << " " << n << endl;
        }
    }

    return 0;
}