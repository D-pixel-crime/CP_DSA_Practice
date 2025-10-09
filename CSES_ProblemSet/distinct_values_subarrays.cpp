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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> lastPos;
    int i = 0, j = 0;
    ll ans = 0;

    while (j < n)
    {
        if (lastPos.count(arr[j]) && lastPos[arr[j]] >= i)
        {
            i = lastPos[arr[j]] + 1;
        }
        lastPos[arr[j]] = j;
        ans += (j - i + 1);
        j++;
    }

    cout << ans << endl;

    return 0;
}