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

int Count(Node *root)
{
    int cnt = 0;
    if (root->left == NULL || root->right == NULL)
        cnt++;
    Count(root->left);
    Count(root->right);
}
