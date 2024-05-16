#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
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

bool FullBST(Node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;
    if (root->left == nullptr || root->right == nullptr)
        return false;
    return FullBST(root->left) && FullBST(root->right);
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;
    while (n--)
    {
        int x;
        cin >> x;
        root = InsertNode(root, x);
    }
    cout << boolalpha << FullBST(root);
}