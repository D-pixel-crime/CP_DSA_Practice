#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n;
    ll c;
    cin >> n >> c;

    priority_queue<ll, vector<ll>, greater<>> pq;
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        pq.push(i + temp);
    }

    while (!pq.empty() && pq.top() <= c)
    {
        c -= pq.top();
        pq.pop();
    }

    cout << n - pq.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}