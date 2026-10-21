#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    int j = 1;

    vector<int> arr(n + 1, -1);
    unordered_map<int, int> isThere;

    for (int i = k; i <= n; i += k, j++)
    {
        arr[i] = j;
        isThere[j] = 1;
    }

    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (isThere.find(i) == isThere.end())
            st.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == -1)
        {
            arr[i] = st.top();
            st.pop();
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
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