#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            count[arr[i]]++;
        }

        if (count.size() == 1)
            cout << "YES" << endl;
        else if (count.size() == 2)
        {
            vector<int> temp;
            for (auto &i : count)
                temp.push_back(i.second);

            if (abs(temp[0] - temp[1]) <= 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}