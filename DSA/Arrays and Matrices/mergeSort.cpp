// Sort the array using merge sort

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    int a = start, b = mid + 1, k = 0;
    vector<int> temp(end - start + 1, 0);

    while (a <= mid && b <= end)
    {
        if (arr[a] <= arr[b])
            temp[k++] = arr[a++];
        else
            temp[k++] = arr[b++];
    }

    while (a <= mid)
        temp[k++] = arr[a++];
    while (b <= end)
        temp[k++] = arr[b++];

    k = 0;
    for (int i = start; i <= end; i++, k++)
    {
        arr[i] = temp[k];
    }
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (auto i : arr)
        cout << i << " ";
}