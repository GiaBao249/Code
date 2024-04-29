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

bool snt(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

Node *Test(Node *&head, int k, int m)
{
    Node *newNodeK = makeNode(k);
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->val == snt(m))
        {
            newNodeK->next = temp->next;
            temp->next = newNodeK;
        }
        temp = temp->next;
    }
    return head;
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
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        PushBack(L, x);
    }
    Test(L, 10, 5);
    duyet(L);
    return 0;
}