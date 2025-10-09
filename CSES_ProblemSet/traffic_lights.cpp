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
    cin >> x >> n;

    set<int> points;
    points.insert(0);
    points.insert(x);

    multiset<int> distances;
    distances.insert(x);

    while (n--)
    {
        int p;
        cin >> p;

        if (p == 0)
        {
            continue;
        }

        auto r = points.upper_bound(p), l = r;
        l--;
        int dist = (*r) - (*l);

        auto it = distances.find(dist);
        points.insert(p);
        distances.erase(it);
        distances.insert(p - (*l));
        distances.insert((*r) - p);

        cout << *distances.rbegin() << " ";
    }

    return 0;
}