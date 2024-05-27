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

void Try(Tree *root, int k)
{
    Tree *cur = root;
    queue<Tree *> q;
    bool found = false;
    while (cur != NULL)
    {
        q.push(cur);
        if (cur->data == k)
        {
            found = true;
            break;
        }
        else if (cur->data > k)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (found)
    {
        while (!q.empty())
        {
            cout << q.front()->data << " ";
            q.pop();
        }
    }
    else
        cout << "No" << endl;
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
    Try(root, x);
    return 0;
}