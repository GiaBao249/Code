#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int check(Node *root)
{
    queue<Node *> q;
    int cnt = 0;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        if (s != pow(2, cnt))
            return 0;
        for (int i = 0; i < s; i++)
        {
            Node *u = q.front();
            q.pop();
            if (u->left)
                q.push(u->left);
            else if (u->right)
                q.push(u->right);
        }
        cnt++;
    }
    return 1;
}

Node *Insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);
    return root;
}

int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = Insert(root, x);
    }
    cout << check(root) << endl;
}