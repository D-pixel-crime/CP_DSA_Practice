// Detect if there is loop present in a linked list or not, given the data-points in the LL are unique

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

bool loopDetectLL(Node *head)
{
    Node *fast = head;
    Node *slow = head->next;

    while (true)
    {
        if (fast == nullptr || slow == nullptr)
            return 0;
        if (fast == slow)
            return 1;

        if (fast->next != nullptr)
            fast = fast->next->next;
        else
            fast = fast->next;
        slow = slow->next;
    }
}