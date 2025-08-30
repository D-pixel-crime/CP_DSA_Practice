// A sorted array has been rotated clockwise by k-steps.
// Find the position of an element 'x' in this array

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

int find_pivot_of_rotated_array(vector<int> &arr, int &n)
{
    int start = -1, end = n;
    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0])
            start = mid;
        else
            end = mid;
    }

    return end == n ? 0 : end;
}

void search_in_rotated_sorted_array(vector<int> &arr, int &n, int &x)
{
    int pivot = find_pivot_of_rotated_array(arr, n); // Lowest value of the array.
    int start = -1, end = n;
    if (x >= arr[pivot] && x <= arr[n - 1])
        start = pivot - 1;
    else if (x >= arr[0])
        end = pivot + 1;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < x)
            start = mid;
        else
            end = mid;
    }

    if (arr[end] == x)
        cout << end << endl;
    else
        cout << -1 << endl;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;

    search_in_rotated_sorted_array(arr, n, x);
}