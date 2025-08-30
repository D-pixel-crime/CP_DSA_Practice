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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    unordered_map<int, int> pos;
    for (int i = 1, temp; i <= n; i++)
    {
        cin >> temp;
        if (!pos.count(temp))
        {
            pos[temp] = i;
        }
    }

    while (q--)
    {
        int t;
        cin >> t;

        cout << pos[t] << " ";
        for (auto &i : pos)
        {
            if (i.first != t && i.second <= pos[t])
            {
                pos[i.first] = pos[i.first] + 1;
            }
        }
        pos[t] = 1;
    }

    return 0;
}