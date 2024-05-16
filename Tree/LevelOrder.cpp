#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *InsertNode(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    else if (root->data > x)
        root->left = InsertNode(root->left, x);
    else
        root->right = InsertNode(root->right, x);
    return root;
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    cout << root->data << " ";
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
            cout << temp->left->data << " ";
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
            cout << temp->right->data << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Node *root;
    while (n--)
    {
        int x;
        cin >> x;
        root = InsertNode(root, x);
    }
    levelOrder(root);
    return 0;
}