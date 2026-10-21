#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == b)
        return a;
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}

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

        bool isFound = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int temp = gcd(arr[i], arr[j]);
                if (temp == 1 || temp == 2)
                {
                    isFound = true;
                    break;
                }
            }
            if (isFound)
                break;
        }

        if (isFound)
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }

    return 0;
}