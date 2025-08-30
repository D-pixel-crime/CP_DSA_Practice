// Reverse a doubly linked list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *prev = nullptr, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node *reverseDoublyLL(Node *head)
{
    Node *curr = head;
    Node *previous = nullptr;

    while (curr!= nullptr)
    {
        Node *temp = curr->next;
        curr->next = previous;
        curr->prev = temp;
        previous = curr;
        curr = temp;
    }

    return previous;
}

int main()
{
    int n;
    cin >> n;
    Node *curr;
    Node *head;
    Node *previous;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (i == 0)
        {
            head = new Node(temp);
            curr = head;
            previous = head;
        }
        else
        {
            curr = new Node(temp, previous);
            previous->next = curr;
            previous = curr;
        }
    }

    curr = head;

    cout << "Original doubly linked list: ";
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    head = reverseDoublyLL(head);

    cout << "Reversed doubly linked list: ";
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}