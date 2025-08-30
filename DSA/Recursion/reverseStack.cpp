#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void insertAtBack(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }

    int top = st.top();
    st.pop();

    insertAtBack(st, element);

    st.push(top);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();

    reverseStack(st);

    insertAtBack(st, top);
}

int main()
{
    fastread;
    int n;
    cin >> n;
    stack<int> st;
    while (n--)
    {
        int temp;
        cin >> temp;
        st.push(temp);
    }

    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}