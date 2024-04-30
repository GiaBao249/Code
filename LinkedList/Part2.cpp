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

void *FrontPush(Node *&head, int k)
{
    Node *newNode = makeNode(k);
    newNode->next = head;
    head = newNode;
}

Node *Test(Node *&head, int k)
{
    int m = 2 * k + 3;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == m)
        {
            temp->data = k;
        }
        temp = temp->next;
    }
    return head;
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
    // FrontPush(head, 10);
    Test(head, 3);
    duyet(head);
}