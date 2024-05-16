#include <iostream>
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

Node *InsertNodeTreeBinary(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (key < root->data)
        root->left = InsertNodeTreeBinary(root->left, key);
    else if (key > root->data)
        root->right = InsertNodeTreeBinary(root->right, key);
    return root;
}

int Height(Node *root)
{
    if (root == NULL)
        return -1;
    return max(Height(root->left) + 1, Height(root->right) + 1);
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
        root = InsertNodeTreeBinary(root, x);
    }
    cout << Height(root) << endl;
}
