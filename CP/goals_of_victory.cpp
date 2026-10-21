#include <iostream>
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
        int sum = 0;
        while (n-- > 1)
        {
            int temp;
            cin >> temp;
            sum += temp;
        }

        cout << -(sum) << endl;
    }

    return 0;
}