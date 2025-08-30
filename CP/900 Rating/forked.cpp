#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, kx, ky, qx, qy;
        cin >> a >> b;
        cin >> kx >> ky;
        cin >> qx >> qy;

        vector<vector<pair<ll, ll>>> directions = {{{-b, a}, {b, a}}, {{a, -b}, {a, b}}, {{-b, -a}, {b, -a}}, {{-a, -b}, {-a, b}}};

        set<pair<ll, ll>> first;
        for (auto &i : directions)
        {
            for (auto j : i)
            {
                ll newX = kx + j.first;
                ll newY = ky + j.second;

                first.insert({newX, newY});
            }
        }

        set<pair<ll, ll>> second;
        for (auto &i : directions)
        {
            for (auto j : i)
            {
                ll newX = qx + j.first;
                ll newY = qy + j.second;

                if (first.find({newX, newY}) != first.end())
                    second.insert({newX, newY});
            }
        }

        cout << second.size() << "\n";
    }

    return 0;
}