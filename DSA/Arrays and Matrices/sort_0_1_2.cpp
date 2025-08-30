// Sort the 0's and 1's and 2's in an array without sort function

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

void sort_0_1_2(vector<int> &arr)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    vector<int> temp(n, 0);
    for (int i = 0; i < n && start < end; i++)
    {
        if (arr[i] == 0)
        {
            temp[start++] = 0;
        }
        else if (arr[i] == 2)
        {
            temp[end--] = 2;
        }
    }
    for (int i = start; i <= end; i++)
        temp[i] = 1;

    arr = temp;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort_0_1_2(arr);
    for (auto i : arr)
        cout << i << " ";
}