// You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;

    int start = -1, end = n;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] - (mid + 1) < k)
            start = mid;
        else
            end = mid;
    }

    if (end == 0 || start == -1)
    {
        cout << k << endl;
    }
    else
        cout << arr[start] + (k) - (arr[start] - (start + 1)) << endl;

    return 0;
}