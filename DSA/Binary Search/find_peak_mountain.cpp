// Given a mountain array such that arr[0] < arr[1] .... < arr[i] > arr[i + 1] > ..... arr[n - 1]
// Find the peak of such array

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

void find_peak_mountain_array(vector<int> &arr)
{
    int start = -1, end = arr.size() - 1;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (mid != arr.size() - 1 && arr[mid] < arr[mid + 1])
            start = mid;
        else if (mid != arr.size() - 1 && arr[mid] > arr[mid + 1])
            end = mid;
    }

    cout << end << endl;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    if (n < 3)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    find_peak_mountain_array(arr);
}