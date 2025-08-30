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
        vector<char> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        int ans = 0;
        int i = 0;

        bool isLongerThan2 = false;

        while (i < n)
        {
            while (s[i] == '#')
                i++;
            int j = i;
            while (j < n && s[j] == '.')
                j++;
            j--;
            if (i <= j)
            {
                int len = j - i + 1;
                if (len > 2)
                {
                    ans = 2;
                    break;
                }
                if (len < 2)
                    ans += len;
                else
                    ans += 2;
            }

            i = j + 1;
        }

        cout << ans << endl;
    }

    return 0;
}