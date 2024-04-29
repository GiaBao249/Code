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

Node *Test(Node *&List1, Node *&List2)
{
    if (List1 == NULL)
        return List2;
    if (List2 == NULL)
        return List1;
    if (List1->val <= List2->val)
    {
        List1->next = Test(List1->next, List2);
        return List1;
    }
    else
    {
        List2->next = Test(List1, List2->next);
        return List2;
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
    Node *M = NULL;
    ListInitialize(L);
    ListInitialize(M);
    PushBack(L, 0);
    PushBack(L, 1);
    PushBack(L, 5);
    PushBack(M, 2);
    PushBack(M, 3);
    PushBack(M, 7);
    Test(L, M);
    duyet(L);
    return 0;
}