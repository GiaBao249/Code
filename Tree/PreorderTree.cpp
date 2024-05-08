#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *Insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);
    return root;
}

void Preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        root = Insert(root, u);
    }
    Preorder(root);
    return 0;
}
