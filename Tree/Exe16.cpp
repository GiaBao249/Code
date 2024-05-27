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

void Print(Tree *root)
{
    if (root != NULL)
    {
        Print(root->left);
        cout << root->data << " ";
        Print(root->right);
    }
}

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

int Try(Tree *root)
{
    if (!root)
        return 0;
    int hLeft = Try(root->left);
    int hRight = Try(root->right);
    return 1 + max(hRight, hLeft);
}

int main()
{
    Tree *root = NULL;
    fstream fs("File.txt");
    int n;
    fs >> n;
    while (n--)
    {
        int x;
        fs >> x;
        root = Insert(root, x);
    }
    cout << Try(root) << endl;
    return 0;
}