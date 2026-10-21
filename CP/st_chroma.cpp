#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, x;
    cin >> n >> x;

    if(x >= n - 1){
        for(int i = 0; i < n; i++)cout << i << " ";
        cout << endl;
        return;
    }

    int i = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == x && i != n - 1)
            i++;
        cout << i << " ";
    }
    cout << x << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}