// Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board.
// Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.


#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool is_possible(vector<int> &arr, int &mid, int &k)
{
    int total = 0, count = 1;
    for (auto i : arr)
    {
        if (total <= mid - i)
            total += i;
        else
        {
            total = i;
            count++;
        }
    }

    return count <= k;
}

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
    int start = *max_element(arr.begin(), arr.end()) - 1, end = accumulate(arr.begin(), arr.end(), 0) + 1, temp = end;

    while (start + 1 < end)
    {
        int mid = start + (end - start) / 2;
        if (is_possible(arr, mid, k))
            end = mid;
        else
            start = mid;
    }

    if (end != temp)
        cout << end << endl;
    else
        cout << -1 << endl;

    return 0;
}