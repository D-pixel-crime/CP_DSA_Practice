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

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0, a, b; i < n; i++)
    {
        cin >> a >> b;
        pq.push({a, 1});
        pq.push({b, -1});
    }

    int ans = 0, curr = 0;
    while (!pq.empty())
    {
        auto [event, weight] = pq.top();
        pq.pop();
        curr += weight;
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}