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

int Try(Tree *root)
{
    int res = 0;
    if (root == NULL)
        return 0;
    if ((root->left != NULL && root->right != NULL))
        res += root->data;
    res += Try(root->left);
    res += Try(root->right);
    return res;
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
    fs.close();
    return 0;
}
