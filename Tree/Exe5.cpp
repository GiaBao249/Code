#include <iostream>
#include <fstream>
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
    if (root)
    {
        Print(root->right);
        if (root->data % 2 == 0)
            cout << root->data << " ";
        Print(root->left);
    }
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
    Print(root);
    return 0;
}