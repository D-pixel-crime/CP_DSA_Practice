#include <bits/stdc++.h>
using namespace std;

constexpr int LIM = 2e5 + 5;
int anc[LIM][31];

int kthAnc(int node, int k)
{
    for (int i = 0; i <= 30; i++)
    {
        if (k & (1 << i))
        {
            node = anc[node][i];
        }
        if (node == -1)
        {
            break;
        }
    }

    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    memset(anc, -1, sizeof(anc));

    for (int i = 1; i <= n; i++)
    {
        cin >> anc[i][0];
    }

    for (int d = 1; d <= 30; d++)
    {
        for (int i = 1; i <= n; i++)
        {
            anc[i][d] = anc[anc[i][d - 1]][d - 1];
            if (anc[i][d] == -1)
            {
                break;
            }
        }
    }

    int start, k;
    while (q--)
    {
        cin >> start >> k;
        cout << kthAnc(start, k) << "\n";
    }

    return 0;
}