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

bool Try(Tree *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;
    else if (root->data > x)
        return Try(root->left, x);
    else
        return Try(root->right, x);
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
    int x;
    fs >> x;
    cout << boolalpha << Try(root, x) << endl;
    return 0;
}