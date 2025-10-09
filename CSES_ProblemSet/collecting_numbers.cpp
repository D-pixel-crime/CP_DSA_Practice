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

    vector<int> pos(n + 1);
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        pos[temp] = i;
    }

    int curr = 1;
    int ans = 1;
    while (curr < n)
    {
        if (pos[curr + 1] < pos[curr])
        {
            ans++;
        }
        curr++;
    }

    cout << ans << endl;

    return 0;
}