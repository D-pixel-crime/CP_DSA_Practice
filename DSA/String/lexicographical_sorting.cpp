// Given 'n' lowercased strings, sort them in lexicographical order

#include <bits/stdc++.h>
using namespace std;

void lexicographicalSort(vector<string> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int posToSwitch = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[posToSwitch])
            {
                posToSwitch = j;
            }
        }
        swap(arr[i], arr[posToSwitch]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    lexicographicalSort(arr);

    for (auto str : arr)
        cout << str << endl;
}