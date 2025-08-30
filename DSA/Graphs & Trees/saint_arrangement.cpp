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

    unordered_map<int, bool> placed, temples;
    queue<pair<int, int>> q;
    while (n--)
    {
        int temp;
        cin >> temp;
        placed[temp] = true;
        temples[temp] = true;
        q.push({temp, temp});
    }

    ll ans = 0;
    while (!q.empty())
    {
        auto [start, node] = q.front();
        q.pop();

        if (m <= 0)
        {
            placed.erase(node);
            continue;
        }

        ans += abs(start - node);
        if (!temples.count(node))
        {
            m--;
        }

        if (!placed.count(node + 1))
        {
            placed[node + 1] = true;
            q.push({start, node + 1});
        }
        if (!placed.count(node - 1))
        {
            placed[node - 1] = true;
            q.push({start, node - 1});
        }
    }

    cout << ans << endl;
    for (auto &i : placed)
    {
        if (!temples.count(i.first))
        {
            cout << i.first << " ";
        }
    }

    return 0;
}