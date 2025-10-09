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

    int n;
    cin >> n;

    ll sum = (1LL * n * (n + 1)) / 2;
    if (sum & 1)
    {
        cout << "NO\n";
    }
    else
    {
        ll half = sum / 2;

        set<int> first;
        ll curr = 0;
        int i = n;

        while (half - curr >= i)
        {
            curr += i;
            first.insert(i);
            i--;
        }

        first.insert(half - curr);
        first.erase(0);
        cout << "YES\n"
             << first.size() << endl;
        for (auto i : first)
        {
            cout << i << " ";
        }
        cout << endl
             << n - first.size() << endl;
        for (int j = 1; j <= n; j++)
        {
            if (!first.count(j))
            {
                cout << j << " ";
            }
        }
    }

    return 0;
}