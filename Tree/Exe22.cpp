#include <bits/stdc++.h>
using namespace std;

//      8
//    /   \
//   3    10
//  / \   / \
// 1   6 9  14
//    / \
//   4   7

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

bool Try(Tree *root1, Tree *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->data != root2->data)
        return false;
    return Try(root1->left, root2->left) && Try(root2->right, root2->right);
}

int main()
{
    Tree *root1 = NULL;
    Tree *root2 = NULL;
    fstream fs("File.txt");
    int n;
    fs >> n;
    while (n--)
    {
        int x;
        fs >> x;
        root1 = Insert(root1, x);
    }
    int m;
    fs >> m;
    while (m--)
    {
        int x;
        fs >> x;
        root2 = Insert(root2, x);
    }
    cout << boolalpha << Try(root1, root2);
    fs.close();
    return 0;
}
