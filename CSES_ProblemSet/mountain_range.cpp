#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

vector<ll> seg;

void update(int i, int start, int end, int &idx, ll &val)
{
    if (start == end)
    {
        seg[i] = val;
        return;
    }

    int mid = start + (end - start) / 2;
    if (idx <= mid)
    {
        update(2 * i + 1, start, mid, idx, val);
    }
    else
    {
        update(2 * i + 2, mid + 1, end, idx, val);
    }

    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
}

ll getMax(int i, int start, int end, const int &l, const int &r)
{
    if (l > r || start > r || end < l)
    {
        return 0;
    }
    if (start >= l && end <= r)
    {
        return seg[i];
    }

    int mid = start + (end - start) / 2;
    return max(getMax(2 * i + 1, start, mid, l, r), getMax(2 * i + 2, mid + 1, end, l, r));
}

void calcGt(vector<pair<ll, int>> &arr, vector<int> &pre, vector<int> &nxt)
{
    vector<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.back()].first < arr[i].first)
        {
            st.pop_back();
        }
        if (!st.empty())
        {
            pre[i] = st.back();
        }
        st.push_back(i);
    }

    st.clear();
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.back()].first < arr[i].first)
        {
            st.pop_back();
        }
        if (!st.empty())
        {
            nxt[i] = st.back();
        }
        st.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<ll, int>> arr(n);
    vector<int> pre(n, -1), nxt(n, n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    seg = vector<ll>(4 * n);
    calcGt(arr, pre, nxt);
    sort(arr.begin(), arr.end());

    ll ans = 1;
    for (auto &[val, i] : arr)
    {
        int a = pre[i], b = nxt[i];
        ll dp = getMax(0, 0, n - 1, a + 1, b - 1) + 1;
        ans = max(dp, ans);
        update(0, 0, n - 1, i, dp);
    }

    cout << ans << endl;

    return 0;
}