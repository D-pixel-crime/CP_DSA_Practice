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

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(all(arr));
    ll curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curr + 1)
        {
            cout << curr + 1 << endl;
            return 0;
        }
        curr += arr[i];
    }

    cout << curr + 1 << endl;

    return 0;
}