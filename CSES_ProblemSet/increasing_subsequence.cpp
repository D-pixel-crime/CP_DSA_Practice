#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> lis;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        if (lis.empty() || lis.back() < temp)
        {
            lis.push_back(temp);
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), temp);
            *it = temp;
        }
    }

    cout << lis.size() << endl;

    return 0;
}