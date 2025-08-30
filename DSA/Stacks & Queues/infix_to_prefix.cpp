#include <bits/stdc++.h>
using namespace std;

int precedence(char a)
{
    if (a == '^')
        return 3;
    if (a == '*' || a == '/')
        return 2;
    if (a == '+' || a == '-')
        return 1;
    return 0;
}

bool isInsideGreater(char a, char b)
{
    if (a == '^' && b == '^')
        return false;
    return precedence(a) > precedence(b);
}

string infixToPrefix(string &exp)
{
    stack<char> st;
    reverse(exp.begin(), exp.end());

    string ans = "";
    for (auto ch : exp)
    {
        if (isalnum(ch))
            ans.push_back(ch);
        else if (ch == ')')
            st.push(ch);
        else if (ch == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                ans.push_back(st.top());
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && st.top() != ')' && isInsideGreater(st.top(), ch))
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        if (st.top() == ')')
            st.pop();
        else
        {
            ans.push_back(st.top());
            st.pop();
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        cout << infixToPrefix(s) << endl;
    }

    return 0;
}