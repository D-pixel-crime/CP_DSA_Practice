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

    multiset<int> topOfTowers;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;

        auto itr = topOfTowers.upper_bound(temp);

        if (itr != topOfTowers.end())
        {
            topOfTowers.erase(itr);
        }

        topOfTowers.insert(temp);
    }

    cout << topOfTowers.size() << endl;

    return 0;
}