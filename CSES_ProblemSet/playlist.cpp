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

    set<int> unique;
    int i = 0, j = 0, ans = 0;
    while (j < n)
    {
        if (!unique.count(arr[j]))
        {
            ans = max(ans, j - i + 1);
        }
        else
        {
            while (arr[i] != arr[j])
            {
                unique.erase(arr[i]);
                i++;
            }
            unique.erase(arr[i]);
            i++;
        }
        unique.insert(arr[j]);
        j++;
    }

    cout << ans << endl;

    return 0;
}