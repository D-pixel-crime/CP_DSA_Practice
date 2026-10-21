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
        int n;
        cin >> n;

        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<ll> a, b;

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; i++)
        {
            a.push_back(arr[i]);
        }

        b.push_back(arr[n - 1]);

        while (a.size() != 0 && a.back() == b.back())
        {
            b.push_back(a.back());
            a.pop_back();
        }

        if (a.size() == 0 || b.size() == 0)
        {
            cout << -1 << endl;
            continue;
        }

        cout << a.size() << " " << b.size() << endl;

        for (auto i : a)
            cout << i << " ";
        cout << endl;
        for (auto i : b)
            cout << i << " ";

        cout << endl;
    }

    return 0;
}