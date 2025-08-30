// Find maximum subarray sum in an array
// Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

ll kadane_maximum_subarray_sum(vector<ll> &arr)
{
    ll ans = LONG_LONG_MIN;
    ll curr = 0;
    vector<ll> currArr;
    vector<ll> ansArr;
    for (auto i : arr)
    {
        if (curr + i > i)
        {
            curr += i;
        }
        else
        {
            curr = i;
            currArr.clear();
        }
        currArr.push_back(i);
        if (curr >= ans)
        {
            ans = curr;
            ansArr = currArr;
        }
    }

    cout << "Maximum sum subarray is : ";
    for (auto i : ansArr)
        cout << i << " ";
    cout << endl;
    return ans;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << kadane_maximum_subarray_sum(arr) << endl;
}