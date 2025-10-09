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

// Implementing Quick Sort by RANDOM PIVOT
void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = start + (rand() % (end - start + 1));
    int target = arr[pivot];
    swap(arr[end], arr[pivot]);

    int i = start, j = end - 1;
    while (i <= j)
    {
        if (arr[i] > target && arr[j] <= target)
        {
            swap(arr[i++], arr[j--]);
        }
        else if (arr[i] <= target)
        {
            i++;
        }
        else if (arr[j] > target)
        {
            j--;
        }
    }
    swap(arr[i], arr[end]);

    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0));
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}