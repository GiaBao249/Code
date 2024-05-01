#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void reversePrint(Node *head)
{
    stack<int> st;
    Node *temp = head;
    if (head == NULL)
        return;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

void ReversePrint(Node *&head)
{
    if (head == NULL)
        return;
    ReversePrint(head->next);
    cout << head->data << endl;
}