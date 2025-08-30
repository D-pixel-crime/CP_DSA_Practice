#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n;
    cin >> n;

    unordered_map<int, int> x;
    unordered_map<int, int> y;

    int left1 = INT_MAX, left2 = INT_MAX;
    int right1 = INT_MIN, right2 = INT_MIN;
    int bottom1 = INT_MAX, bottom2 = INT_MAX;
    int top1 = INT_MIN, top2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int p, q;
        cin >> p >> q;

        x[p]++;
        y[q]++;

        if (p < left1)
        {
            left2 = left1;
            left1 = p;
        }
        else if (p < left2 && p != left1)
        {
            left2 = p;
        }

        if (p > right1)
        {
            right2 = right1;
            right1 = p;
        }
        else if (p > right2 && p != right1)
        {
            right2 = p;
        }

        if (q < bottom1)
        {
            bottom2 = bottom1;
            bottom1 = q;
        }
        else if (q < bottom2 && q != bottom1)
        {
            bottom2 = q;
        }

        if (q > top1)
        {
            top2 = top1;
            top1 = q;
        }
        else if (q > top2 && q != top1)
        {
            top2 = q;
        }
    }

    if (n <= 1)
    {
        cout << n << endl;
        return;
    }

    ll ans = LLONG_MAX;
    bool isOk = false;

    if (x[left1] == 1)
    {
        ll temp;
        if (x[left2] != abs(top1 - bottom1) + 1 && left2 + 1 <= 1e9)
            temp = 1LL * (abs(left2 - right1) + 1) * (abs(top1 - bottom1) + 1);
        else
            temp = 1LL * (abs(left2 - right1) + 1) * (abs(top1 - bottom1) + 2);
        ans = min(ans, temp);
        isOk = true;
    }
    if (x[right1] == 1)
    {
        ll temp;
        if (x[right2] != abs(top1 - bottom1) + 1 && right2 - 1 >= 1e9)
            temp = 1LL * (abs(left1 - right2) + 1) * (abs(top1 - bottom1) + 1);
        else
            temp = 1LL * (abs(left1 - right2) + 1) * (abs(top1 - bottom1) + 2);
        ans = min(ans, temp);
        isOk = true;
    }
    if (y[top1] == 1)
    {
        ll temp;
        if (y[top2] != abs(left1 - right1) + 1 && top2 - 1 >= 1e9)
            temp = 1LL * (abs(left1 - right1) + 1) * (abs(top2 - bottom1) + 1);
        else
            temp = 1LL * (abs(left1 - right1) + 2) * (abs(top2 - bottom1) + 1);
        ans = min(ans, temp);
        isOk = true;
    }
    if (y[bottom1] == 1)
    {
        ll temp;
        if (y[bottom2] != abs(left1 - right1) + 1 && bottom2 + 1 <= 1e9)
            temp = 1LL * (abs(left1 - right1) + 1) * (abs(top1 - bottom2) + 1);
        else
            temp = 1LL * (abs(left1 - right1) + 2) * (abs(top1 - bottom2) + 1);
        ans = min(ans, temp);
        isOk = true;
    }

    if (isOk)
        cout << ans << endl;
    else
        cout << 1LL * (abs(left1 - right1) + 1) * (abs(top1 - bottom1) + 1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}