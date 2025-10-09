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

    int n, m;
    cin >> n >> m;

    multiset<int> prices;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        prices.insert(temp);
    }

    for (int i = 0, temp; i < m; i++)
    {
        cin >> temp;

        auto itr = prices.upper_bound(temp);
        if (itr == prices.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *(--itr) << endl;
            prices.erase(itr);
        }
    }

    return 0;
}