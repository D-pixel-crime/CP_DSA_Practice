#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> children(n);
    for (int i = 0; i < n; i++)
        cin >> children[i];

    sort(all(children));

    int ans = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (i == j && children[i] <= x)
        {
            ans++, i++;
        }
        else
        {
            int sum = children[i] + children[j];
            if (sum <= x)
            {
                ans++, i++, j--;
            }
            else
            {
                if (children[j] <= x)
                {
                    ans++;
                }
                j--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}