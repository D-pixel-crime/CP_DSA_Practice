// Find the first and last occurrence of a given integer

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;

    int start = -1, end = n + 1;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < x)
            start = mid;
        else
            end = mid;
    }

    if (end != n + 1 && arr[end] == x)
        cout << end << " ";
    else
        cout << -1 << " ";

    start = -1, end = n + 1;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= x)
            start = mid;
        else
            end = mid;
    }

    if (start != -1 && arr[start] == x)
        cout << start << " ";
    else
        cout << -1 << " ";
}