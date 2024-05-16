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
int Height(Node *root)
{
    if (root == NULL)
        return -1;
    return max(Height(root->left), Height(root->right)) + 1;
}

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

int CheckLeaf(Node *root, int cnt, int h)
{
    if (root == NULL)
        return 1;
    else if (root->left == NULL && root->right == NULL)
        return cnt == h;
    return CheckLeaf(root->left, cnt + 1, h) && CheckLeaf(root->right, cnt + 1, h);
}
int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        root = InsertNodeTreeBinary(root, x);
    }
    int h = Height(root);
    cout << CheckLeaf(root, 1, h);
}