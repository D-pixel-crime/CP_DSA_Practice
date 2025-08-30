#include <bits/stdc++.h>
using namespace std;

#define fastread                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void insertInStack(stack<int> &st, int element)
{
    if (st.empty() || st.top() <= element)
    {
        st.push(element);
        return;
    }

    int top = st.top();
    st.pop();

    insertInStack(st, element);

    st.push(top);
}

void sortStack(stack<int> &st)
{
    if (st.size() <= 1)
        return;

    int top = st.top();
    st.pop();

    sortStack(st);

    insertInStack(st, top);
}

int main()
{
    fastread;
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        st.push(temp);
    }

    sortStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}