#include <iostream>
using namespace std;

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void toiuuSelectionSort(int a[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int min = i;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[min])
                min = j;
        }
        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}
void InsertSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void toiuuInsertSort(int a[], int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        int temp = a[i];
        int j = i + 1;
        while (j < n && a[j] < temp)
        {
            a[j - 1] = a[j];
            j++;
        }
        a[j - 1] = temp;
    }
}

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int cau2a(Node *head)
{
    Node *temp = head;
    if (head == NULL || head->next == NULL)
        return -1;
    int first = 100;
    int second = 100;
    while (temp != NULL)
    {
        if (temp->data < first)
        {
            second = first;
            first = temp->data;
        }
        else if (temp->data < second && temp->data != first)
        {
            second = temp->data;
        }
        temp = temp->next;
    }
    return (second != 0) ? second : -1;
}

void Cau2b(Node *head, int k)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data > k)
        {
            cout << temp->data << " ";
        }
        temp = temp->next;
    }
}

void deleteNode(Node *&head, int k)
{
    if (head == NULL)
        return;
    if (head->data == k)
    {
        head = head->next;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == k)
        {
            Node *nextNode = temp->next;
            temp->next = nextNode->next;
        }
        else
            temp = temp->next;
    }
}

Node *cau2c(Node *&head, int k)
{
    Node *temp = head;
    while (temp && temp->data < k)
    {
        deleteNode(head, temp->data);
        temp = head;
    }
    temp = head;
    while (temp != NULL && temp->next)
    {
        if (temp->next->data < k)
            deleteNode(head, temp->next->data);
        else
            temp = temp->next;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
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

int a[20], b[20], c[20];
int x = 0, y = 0, z = 0;
int MUC(Tree *root, int h)
{
}

void NUT2con(Tree *&root)
{
    if (root == NULL)
        return;
    if (root->left && root->right)
    {
        b[y++] = root->data;
    }
    NUT2con(root->left);
    NUT2con(root->right);
}

void Leaf(Tree *root)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
        c[z++] = root->data;
    Leaf(root->left);
    Leaf(root->right);
}

int height(Tree *root)
{
    if (root == NULL)
        return -1;
    return max(height(root->left) + 1, height(root->right) + 1);
}

int SumLeaf(Tree *root)
{
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return SumLeaf(root->left) + SumLeaf(root->right);
}

double cau3d(Tree *root)
{
    if (root == NULL)
        return 0;
    int cnt1 = SumLeaf(root->left);
    int cnt2 = SumLeaf(root->right);
    return 1.0 * (cnt1) / cnt2;
}

Tree *InsertTree(Tree *root, int x)
{
    if (root == NULL)
        return new Tree(x);
    if (x > root->data)
        root->right = InsertTree(root->right, x);
    else if (x < root->data)
        root->left = InsertTree(root->left, x);
    return root;
}

int main()
{
    Tree *root = NULL;
    int k[13] = {50, 61, 24, 13, 73, 99, 51, 4, 9, 10, 41, 52, 64};
    for (int i = 0; i < 13; i++)
    {
        root = InsertTree(root, k[i]);
    }
    NUT2con(root);
    Leaf(root);
    for (int i = 0; i < y; ++i)
        cout << b[i] << " ";
    cout << endl;
    for (int i = 0; i < z; i++)
        cout << c[i] << " ";
    cout << endl;
    cout << height(root) << endl;
    cout << cau3d(root) << endl;
    return 0;
}