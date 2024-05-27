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

int d[1005];

void Try(Tree *root, int cnt)
{
    d[root->data] = cnt;
    if (root->right)
        Try(root->right, cnt + 1);
    if (root->left)
        Try(root->left, cnt + 1);
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
    Try(root, 0);
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    fs.close();
    return 0;
}
