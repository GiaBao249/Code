#include <bits/stdc++.h>
using namespace std;

struct List
{
    int data;
    List *next;
    List(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Tree
{
    int data;
    Tree *left, *right;
    Tree(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void PushBack(List *&head, int x)
{
    List *newNode = new List(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    List *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void TreeToList(Tree *root, List *&head)
{
    if (root != NULL)
    {
        TreeToList(root->left, head);
        PushBack(head, root->data);
        TreeToList(root->right, head);
    }
}

Tree *Insert(Tree *root, int x)
{
    if (root == NULL)
        return new Tree(x);
    if (x < root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);
    return root;
}

void Print(List *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Tree *root = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        root = Insert(root, x);
    }
    List *head = NULL;
    TreeToList(root, head);
    Print(head);
}