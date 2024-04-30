#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *makeNode(int x)
{
    node *newNode = new node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->prev = NULL;
    return newNode;
}

void duyet(node *head)
{
    while (head != NULL)
    {
        cout << head->data < ' ';
        head->next;
    }
    cout << endl;
}

void PushFront(node *&head, int x)
{
    node *newNode = makeNode(x);
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void PushBack(node *&head, int x)
{
    node *newNode = makeNode(x);
    node *temp = head;
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
    newNode->prev = temp;
}

int size(node *&head)
{
    int ans = 0;
    while (head != 0)
    {
        ++ans;
        head = head->next;
    }
    return ans;
}
void Erase(node *&head, int x, int k)
{
    n = size(head);
    if (k < 1 || k > n + 1)
        return;
    if (head == NULL)
        PushFront(head, x);

    node *temp = head;
    for (int i = 1; i <= k - 1; i++)
    {
        temp = temp->next;
    }
    // temp == vi tri cua k
    node *newNode = makeNode(x);
    newNode->next = temp;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode;
}
