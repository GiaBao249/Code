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

int countNodesAtLevel(Tree *root, int level)
{
    if (root == nullptr || level < 0)
        return 0;
    if (level == 0)
    {
        cout << root->data << " ";
        return 1;
    }
    return countNodesAtLevel(root->left, level - 1) + countNodesAtLevel(root->right, level - 1);
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
    cout << countNodesAtLevel(root, x);
    fs.close();
    return 0;
}
