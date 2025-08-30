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
        int n, x;
        cin >> n >> x;
        bool isThere = false;
        while (n--)
        {
            int temp;
            cin >> temp;
            if (temp == x)
                isThere = true;
        }

        cout << (isThere ? "Yes" : "No") << endl;
    }

    return 0;
}