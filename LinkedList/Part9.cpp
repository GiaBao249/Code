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

void ListInsert(Node *&L, int k)
{
    Node *x = new Node;
    x->val = k;
    x->next = L;
    L = x;
}

Node *Test(Node *&head, int k)
{
    Node *temp = head;
    Node *newNode = makeNode(k);
    if (temp->next == NULL)
    {
        temp->next = newNode;
        return head;
    }
    Test(temp->next, k);
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
    ListInsert(L, 0);
    ListInsert(L, 1);
    ListInsert(L, 2);
    ListInsert(L, 3);
    ListInsert(L, 4);
    Test(L, 5);
    duyet(L);
    return 0;
}
