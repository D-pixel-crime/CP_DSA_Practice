#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

struct Circle
{
    ll x, y, r;
    Circle(ll x, ll y, ll r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }
};

bool checkIntersect(ll &x1, ll &y1, ll &r1, ll &x2, ll &y2, ll &r2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) <= r2 + r1;
}

bool checkLeftAndTop(vector<Circle *> &arr, set<int> &visited, queue<int> &q, ll &x, ll &y)
{
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            auto node = arr[q.front()];
            q.pop();
            if (node->r + node->y >= y || node->x + node->r >= x)
            {
                return false;
            }

            for (int j = 0; j < arr.size(); j++)
            {
                if (!visited.count(j) && checkIntersect(node->x, node->y, node->r, arr[j]->x, arr[j]->y, arr[j]->r))
                {
                    visited.insert(j);
                    q.push(j);
                }
            }
        }
    }

    return true;
}

bool checkBottomAndRight(vector<Circle *> &arr, set<int> &visited, queue<int> &q, ll &x, ll &y)
{
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            auto node = arr[q.front()];
            q.pop();
            if (node->r + node->y >= y || node->x + node->r >= x)
            {
                return false;
            }

            for (int j = 0; j < arr.size(); j++)
            {
                if (!visited.count(j) && checkIntersect(node->x, node->y, node->r, arr[j]->x, arr[j]->y, arr[j]->r))
                {
                    visited.insert(j);
                    q.push(j);
                }
            }
        }
    }

    return true;
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    int n;
    cin >> n;

    vector<Circle *> arr(n);
    for (int i = 0, a, b, c; i < n; i++)
    {
        cin >> a >> b >> c;
        arr[i] = new Circle(a, b, c);
    }

    set<int> visited;
    queue<int> q;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]->x <= arr[i]->r)
        {
            q.push(i);
            visited.insert(i);
        }
    }

    if (!checkLeftAndTop(arr, visited, q, x, y))
    {
        cout << "NO\n";
        return;
    }

    while (!q.empty())
        q.pop();
    visited.clear();

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]->y <= arr[i]->r)
        {
            q.push(i);
            visited.insert(i);
        }
    }

    if (!checkBottomAndRight(arr, visited, q, x, y))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}