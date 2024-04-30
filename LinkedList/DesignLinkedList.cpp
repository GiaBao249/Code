#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *makeNode(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void PrintNode(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void KT(Node *&head)
{
    head = NULL;
}

void PushFront(Node *&head, int x)
{
    Node *newNode = makeNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void PushBack(Node *&head, int x)
{
    Node *temp = head;
    Node *newNode = makeNode(x);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertNode(Node *&head, int x, int k)
{
    int n = sizeof(head);
    Node *temp = head;
    if (k > n + 1 || k < 1)
        return;
    else if (k == 1)
    {
        PushFront(head, x);
        return;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i <= k - 2; i++)
        {
            temp = temp->next;
        }
        Node *newNode = makeNode(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void PopFront(Node *&head)
{
    if (head == NULL)
        return;
    else
        head = head->next;
}

void PopBack(Node *&head)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

void Erase(Node *&head, int k)
{
    int n = sizeof(head);
    if (k > n + 1 || k < 1)
        return;
    else if (k == 1)
        PopFront(head);
    else
    {
        Node *temp = head;
        for (int i = 1; i <= k - 2; i++)
            temp = temp->next;
        temp->next = temp->next->next;
    }
}

int Count(Node *&head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{
    Node *head = nullptr;
    KT(head);
    for (int i = 0; i < 10; i++)
    {
        PushBack(head, i);
    }
    Erase(head, 3);
    PrintNode(head);
}