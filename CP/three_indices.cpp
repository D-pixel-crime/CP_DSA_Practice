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

    vector<int> arr(n);
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            prev[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            if (prev[i] != -1)
            {
                cout << "YES\n"
                     << prev[i] + 1 << " " << i + 1 << " " << st.top() + 1 << endl;
                return;
            }
        }
        st.push(i);
    }

    cout << "NO\n";
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