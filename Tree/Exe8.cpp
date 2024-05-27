#include <iostream>
#include <fstream>
#include <stack>
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

int Try(Tree *root)
{
    if (!root)
        return 0;
    return root->data + Try(root->left) + Try(root->right);
}

int STACK(Tree *root)
{
    int res = 0;
    stack<Tree *> st;
    Tree *cur = root;
    while (!st.empty() || cur)
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        res += cur->data;

        cur = cur->right;
    }
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
    cout << STACK(root) << "\n";
    return 0;
}