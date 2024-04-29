#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

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

int Test(Node *head)
{
    int sum = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->val % 2 == 1)
            sum += temp->val;
        temp = temp->next;
    }
    return sum;
}

int main()
{
    Node *L = NULL;
    ListInitialize(L);
    ListInsert(L, 0);
    ListInsert(L, 11);
    ListInsert(L, 10);
    ListInsert(L, 13);
    ListInsert(L, 17);
    cout << Test(L);
    return 0;
}
