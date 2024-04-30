#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *makeNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void PushBack(Node *&head, int data)
{
    Node *temp = head;
    Node *newNode = makeNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void ListInitialize(Node *&L)
{
    L = NULL;
}

int Test(Node *&head)
{
    Node *temp = head;
    if (temp == NULL)
        return 0;
    return Test(temp->next) + (temp->data % 2 == 0);
}

void duyet(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    ListInitialize(head);
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        PushBack(head, x);
    }
    cout << Test(head);
    // duyet(head);
}