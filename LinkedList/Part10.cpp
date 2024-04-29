#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

void ListInitialize(Node *&L)
{
    L = NULL;
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

Node Test(Node *&head, int k)
{
    Node *cur = head;
    Node *prev = NULL;
    Node *newNode = makeNode(k);
    while (cur != nullptr && k > cur->val)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        prev->next = newNode;
        newNode->next = cur;
    }
}

void duyet(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    Node *L = NULL;
    ListInitialize(L);
    PushBack(L, 0);
    PushBack(L, 1);
    PushBack(L, 3);
    PushBack(L, 4);
    PushBack(L, 10);
    Test(L, 2);
    duyet(L);
    return 0;
}