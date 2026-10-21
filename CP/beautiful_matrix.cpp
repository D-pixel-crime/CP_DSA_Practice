#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                a = i, b = j;
            }
        }
    }

    cout << abs(3 - a) + abs(3 - b) << endl;

    return 0;
}