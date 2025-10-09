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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; i++)
        cin >> desired[i];
    for (int i = 0; i < m; i++)
        cin >> apartments[i];

    sort(all(desired), greater<>());
    sort(all(apartments), greater<>());

    int i = 0, j = 0, ans = 0;
    while (i < n && j < m)
    {
        int leastAcceptable = desired[i] - k, mostAcceptable = desired[i] + k;
        if (apartments[j] >= leastAcceptable && apartments[j] <= mostAcceptable)
        {
            i++, j++, ans++;
        }
        else
        {
            if (apartments[j] < leastAcceptable)
            {
                i++;
            }
            else if (apartments[j] > mostAcceptable)
            {
                j++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}