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

void findBadAreas(vector<pair<int, int>> &badAreas, vector<int> &arr)
{
    int i = 0, n = arr.size();
    while (i < n)
    {
        int j = i + 1;
        while (j < n && arr[j] > arr[j - 1])
        {
            j++;
        }

        if (j - i >= 4)
        {
            badAreas.push_back({i, j - 1});
        }

        i = j;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<pair<int, int>> badAreas;
    findBadAreas(badAreas, arr);

    if (badAreas.size() & 1)
    {
        auto mid = badAreas[badAreas.size() / 2];

        for (int i = 0; i < mid.first; i++)
        {
            cout << "L";
        }
        for (int i = n - 1; i > mid.second; i--)
        {
            cout << "R";
        }
        for (int i = mid.first; i <= mid.second - 3; i++)
        {
            cout << "L";
        }
    }
    else
    {
        int mid = badAreas.size() / 2;
        auto l = badAreas[mid - 1];
        auto r = badAreas[mid];

        for (int i = 0; i < l.first; i++)
        {
            cout << "L";
        }
        for (int i = n - 1; i > r.second; i--)
        {
            cout << "R";
        }
        for (int i = l.first; i <= l.second - 3; i++)
        {
            cout << "L";
        }
        for (int i = r.second; i >= r.first + 3; i--)
        {
            cout << "R";
        }
    }

    cout << endl;
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