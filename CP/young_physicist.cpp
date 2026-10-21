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

    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    while (n--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a += x, b += y, c += z;
    }

    cout << ((a == 0 && b == 0 && c == 0) ? "YES" : "NO") << endl;

    return 0;
}