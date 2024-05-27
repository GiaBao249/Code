#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int res = 0;
int sumEvenGrandparent(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->val % 2 == 0)
    {
        if (root->left && root->left->left)
            res += root->left->left->val;
        if (root->left && root->left->right)
            res += root->left->right->val;
        if (root->right && root->right->left)
            res += root->right->left->val;
        if (root->right && root->right->right)
            res += root->right->right->val;
    }
    sumEvenGrandparent(root->left);
    sumEvenGrandparent(root->right);
    return res;
}