// Rearrange the contents of the array with alternate positive negative without losing the relative order

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

void rearrange_positive_negative(vector<ll> &arr)
{
    int n = arr.size();
    vector<ll> pos, neg;
    for (auto i : arr)
    {
        if (i >= 0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }

    arr.clear();
    int i, j;
    for (i = 0, j = 0; i < pos.size() && j < neg.size(); i++, j++)
    {
        arr.push_back(pos[i]);
        arr.push_back(neg[j]);
    }

    while (i < pos.size())
    {
        arr.push_back(pos[i]);
        i++;
    }
    while (j < neg.size())
    {
        arr.push_back(neg[j]);
        j++;
    }

    for (auto curr : arr)
        cout << curr << " ";

    return;
}

int main()
{
    fastread;
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    rearrange_positive_negative(arr);
}