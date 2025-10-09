/*
You have to perform three types of queries on a dictionary of strings. Initially, the dictionary is empty.

1 s : Insert string s into the dictionary.
2 s : Search for string s in the dictionary and print 1 if it is found, else print 0.
3 s : Search if string s is a prefix of any string in the dictionary and print 1 it is, else print 0.

Input
First line contains an integer q representing the number of queries.

Following q lines contains queries in the format specified in question.

Constraints
1≤q≤10^3
1≤length(s)≤10^4
The string s contains only the lowercase letters a-z.

Output
Print the output of each query in a new line.

Example 1
Input
5
1 termite
2 term
3 term
1 term
2 term
Output
0
1
1

In the first example,
For the first query, we do not print anything.
For the second query, term was not in the dictionary so we output 0.
For the third query, term is a prefix of termite so we output 1.
For the fourth query, we do not print anything.
For the fifth query, as term is now in the dictionary, we output 1.

Example 2
Input
7
1 calling
3 called
3 call
1 caller
1 called
2 calle
3 called
Output
0
1
0
1
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

int mod = 1000000007;
unordered_map<int, int> factVals;

int countBits(int x)
{
    return floor(log2(x)) + 1;
}

vector<bool> simpleSieve(int &n)
{
    vector<bool> arr(n + 1, true);

    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = false;
            }
        }
    }

    return arr;
}

int binaryExponentiation(int x, int n, int m = 1)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * x) % m;
            n--;
        }
        else
        {
            x = (x * x) % m;
            n >>= 2;
        }
    }

    return ans;
}

int extendedEuclidean(int a, int m, int &x, int &y)
{
    if (m == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclidean(m, a % m, x1, y1);
    x = y1;
    y = x1 - (a / m) * y1;
    return gcd;
}

int modularInverse(int a, int m)
{
    int x, y;
    int gcd = extendedEuclidean(a, m, x, y);
    if (gcd != 1)
        return -1;
    return (x % m + m) % m;
}

int fact(int n)
{
    if (n <= 1)
        return 1;
    if (factVals.count(n))
        return factVals[n];
    int ans = 1, i = n;
    while (i >= 2)
    {
        if (factVals.count(i))
        {
            return factVals[n] = (1LL * ans * factVals[i]) % mod;
        }
        else
        {
            ans = (1LL * ans * i) % mod;
            i--;
        }
    }
    return factVals[n] = ans;
}

int nCx(int n, int x)
{
    int num = fact(n);
    int denom = (1LL * fact(x) * fact(n - x)) % mod;
    return (1LL * num * modularInverse(denom, mod)) % mod;
}

class Trie
{
private:
    unordered_map<int, unordered_map<char, int>> dictionary;
    int dictNode;
    unordered_map<int, int> hotnode; // For counting end frequencies

public:
    Trie()
    {
        dictNode = 0;
    }

    void insertString(string &s)
    {
        int curr = 0, i = 0;
        while (i < s.size())
        {
            if (dictionary[curr].count(s[i]))
            {
                curr = dictionary[curr][s[i]];
            }
            else
            {
                dictNode++;
                dictionary[curr].insert(make_pair(s[i], dictNode));
                curr = dictNode;
            }
            i++;
        }

        hotnode[curr]++;
    }

    bool searchString(string &s)
    {
        int curr = 0, i = 0;
        while (i < s.size())
        {
            if (!dictionary[curr].count(s[i]))
            {
                return false;
            }
            curr = dictionary[curr][s[i]];
            i++;
        }

        return hotnode.count(curr);
    }

    bool isPrefix(string &s)
    {
        int curr = 0, i = 0;
        while (i < s.size())
        {
            if (!dictionary[curr].count(s[i]))
            {
                return false;
            }
            curr = dictionary[curr][s[i]];
            i++;
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    Trie dictionary = Trie();

    while (q--)
    {
        int opt;
        string s;

        cin >> opt >> s;

        switch (opt)
        {
        case 1:
            dictionary.insertString(s);
            break;

        case 2:
            cout << (dictionary.searchString(s) ? 1 : 0) << endl;
            break;

        case 3:
            cout << (dictionary.isPrefix(s) ? 1 : 0) << endl;
            break;
        }
    }

    return 0;
}