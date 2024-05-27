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
    else if (x < root->data)
        root->left = Insert(root->left, x);
    return root;
}

int MAX(Tree *root)
{
    if (root->right)
        return MAX(root->right);
    return root->data;
}
int MIN(Tree *root)
{
    if (root->left)
        return MIN(root->left);
    return root->data;
}
int main()
{
    Tree *root = NULL;
    fstream fs("File.txt");
    int n;
    fs >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        fs >> x;
        root = Insert(root, x);
    }
    cout << MIN(root) << endl;
    cout << MAX(root) << endl;
    fs.close();
    return 0;
}
