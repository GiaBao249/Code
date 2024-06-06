#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

//! chỉ thêm 1 cạnh
Node *makeRoot(Node *root, int u, int v, char c)
{
    if (c == 'L')
        root->left = new Node(v);
    else
        root->right = new Node(v);
}

//! Cho v là Node của u
void InsertRoot(Node *root, int u, int v, char c)
{
    if (root == NULL)
        return;
    if (root->data == u)
        makeRoot(root, u, v, c);
    else
    {
        InsertRoot(root->left, u, v, c);
        InsertRoot(root->right, u, u, c);
    }
}

//! Duyêt danh sách cạnh (giửa)
//* (left -> root -> right)
void Inorder(Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

//! Duyệt danh sách cạnh (trước)
//* (root -> left -> right)
void Preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

//! Duyệt danh sách cạnh (sau)
//* (left -> right -> root)
void Postorder(Node *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

//! Duyệt theo level
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

//! Duyệt xoắn ốc
void Spiral(Node *root)
{
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty() || !st2.empty())
    {
        while (!st1.empty())
        {
            Node *top = st1.top();
            st1.pop();
            cout << top->data << " ";
            if (top->right != NULL)
                st2.push(top->right);
            if (top->left != NULL)
                st2.push(top->left);
        }
        while (!st2.empty())
        {
            Node *top = st2.top();
            st2.pop();
            cout << top->data << " ";
            if (top->left != NULL)
                st1.push(top->left);
            if (top->right != NULL)
                st1.push(top->right);
        }
    }
}

//! tìm kiếm nhị phân trên cây
bool SeachTree(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (root->data < key)
        return SeachTree(root->right, key);
    else
        return SeachTree(root->left, key);
}

//! Chèn Node vào cây nhị phân tìm kiếm
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

//! Delete Node Binary Seach
Node *FindMin(Node *root)
{
    Node *tmp = root;
    while (tmp != NULL && tmp->left != NULL)
    {
        tmp = tmp->left;
    }
    return tmp;
}

Node *DeleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = DeleteNode(root->left, key);
    else if (key > root->data)
        root->right = DeleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    return root;
}

//! Đếm Node Lá
int Count(Node *root)
{
    int cnt = 0;
    if (root == NULL)
        return 0;
    if (root->left == NULL || root->right == NULL)
        return 1;
    cnt += Count(root->left);
    cnt += Count(root->right);
    return cnt;
}

//! Độ cao của cây
int Height(Node *root)
{
    if (root == NULL)
        return -1;
    return max(Height(root->left) + 1, Height(root->right) + 1);
}

//! Check full binarySeach Tree
bool CheckFull(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left != NULL && root->right != NULL)
        return CheckFull(root->left) && CheckFull(root->right);
    return true;
}

//! Check cây có cùng mức hay không?
bool Check1(Node *root, int h, int &maxh)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        if (maxh == 0)
        {
            maxh = h;
            return true;
        }
        else
            return h == maxh;
    }
    else
        return Check1(root->left, h + 1, maxh) && Check1(root->right, h + 1, maxh);
}

set<int> se;
void Check2(Node *root, int x)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        se.insert(x);
    Check2(root->left, x + 1);
    Check2(root->right, x + 1);
}

//! Prefect Binary Tree
int ok = 1;
set<int> se;
void Check(Node *root, int x)
{
    if (root->left != NULL && root->right == NULL || root->left == NULL && root->right != NULL)
        ok = 0;
    else if (root->left == NULL && root->right == NULL)
        se.insert(x);
    Check(root->left, x + 1);
    Check(root->right, x + 1);
}

int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (root == NULL)
        {
            root = new Node(u);
            makeRoot(root, u, v, c);
        }
        else
            InsertRoot(root, u, v, c);
    }
    Inorder(root);
}
