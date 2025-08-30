// Find the square root of the given number upto 5 decimal places

#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void find_sqrt(double &x)
{
    double start = 0, end = (x < 1) ? 1 : x;
    double mid = 0;
    int steps = 150;
    while (steps--)
    {
        mid = start + (end - start) / 2;
        if (mid * mid <= x)
            start = mid;
        else
            end = mid;
    }

    cout << fixed << setprecision(5) << mid << endl;
}

int main()
{
    fastread;
    double x;
    cin >> x;
    if (x < 0)
        return 0;
    find_sqrt(x);
}