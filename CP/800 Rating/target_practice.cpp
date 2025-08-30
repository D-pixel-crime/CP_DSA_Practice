#include <bits/stdc++.h>
using namespace std;

int getScore(int &i, int &j)
{
    if (i == 0 || j == 0 || i == 9 || j == 9)
        return 1;
    if (((j == 1 || j == 8) && (i >= 1 && i <= 8)) || ((i == 1 || i == 8) && (j >= 1 && j <= 8)))
        return 2;
    if (((j == 2 || j == 7) && (i >= 2 && i <= 7)) || ((i == 2 || i == 7) && (j >= 2 && j <= 7)))
        return 3;
    if (((j == 3 || j == 6) && (i >= 3 && i <= 6)) || ((i == 3 || i == 6) && (j >= 3 && j <= 6)))
        return 4;
    return 5;
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
        int ans = 0;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                char temp;
                cin >> temp;

                if (temp == 'X')
                {
                    ans += getScore(i, j);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}