#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
    Tree(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Tree *Insert(Tree *root, int x)
{
    if (root == NULL)
        return new Tree(x);
    if (x > root->data)
        root->right = Insert(root->right, x);
    else
        root->left = Insert(root->left, x);
    return root;
}

Tree *findMin(Tree *root)
{
    Tree *cur = root;
    while (cur != NULL && cur->left != NULL)
        cur = cur->left;
    return cur;
}

Tree *DeleteNode(Tree *root, int x)
{
    if (root == NULL)
        return root;
    if (x < root->data)
        root->left = DeleteNode(root->left, x);
    else if (x > root->data)
        root->right = DeleteNode(root->right, x);
    else
    {
        if (root->left == NULL)
        {
            Tree *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Tree *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Tree *temp = findMin(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    return root;
}

void Print(Tree *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Print(root->left);
        Print(root->right);
    }
}

int main()
{
    fstream fs("File.txt");
    Tree *root = NULL;
    int n;
    fs >> n;
    while (n--)
    {
        int x;
        fs >> x;
        root = Insert(root, x);
    }
    int key;
    fs >> key;
    root = DeleteNode(root, key);
    Print(root);
    return 0;
}