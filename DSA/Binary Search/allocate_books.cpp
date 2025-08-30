// Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book.
// There are a ‘m’ number of students, and the task is to allocate all the books to the students.

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

bool is_possible(vector<ll> &arr, ll &mid, int &m)
{
    ll curr = 0;
    int students = 1;
    for (auto i : arr)
    {
        if (i + curr <= mid)
            curr += i;
        else
        {
            curr = i;
            students++;
        }
    }

    return students <= m;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    if(n < m){
        cout << -1 << endl;
        return 0;
    }
    ll start = *max_element(arr.begin(), arr.end()) - 1, end = accumulate(arr.begin(), arr.end(), 0LL) + 1;

    while (start + 1 < end)
    {
        ll mid = start + (end - start) / 2;
        if (is_possible(arr, mid, m))
            end = mid;
        else
            start = mid;
    }

    if (start == 0)
        cout << -1 << endl;
    else
        cout << end << endl;

    return 0;
}