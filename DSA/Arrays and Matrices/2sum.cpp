// Find the pair of numbers in array that sums to the given sum

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

bool sumPair_exists(vector<ll> &arr, ll sum)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        ll temp = arr[i] + arr[j];
        if (temp == sum)
            return true;
        else if (temp > sum)
            j--;
        else
            i++;
    }

    return false;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll sum;
    cin >> sum;
    cout << sumPair_exists(arr, sum) << endl;
}