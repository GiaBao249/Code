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
    root = Insert(root, key);
    Print(root);
    return 0;
}