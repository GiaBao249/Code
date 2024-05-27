#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};

int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            ++i;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    ++i;
    int temp = a[i];
    a[i] = a[r];
    a[r] = temp;
    return i;
}

void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int BSreach(int a[], int x, int l, int r)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            r = mid - 1;
        else
            l = l + 1;
    }
    return -1;
}

Node *InsertList(Node *&head, int x, int k)
{
    Node *newNode = new Node({x, nullptr});
    if (head == NULL)
        return NULL;
    if (k == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
        if (cnt == k - 1)
            break;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int Bai2b(Node *head, int x)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (temp->data == x)
            return cnt;
        temp = temp->next;
    }
    return -1;
}

int Bai2c(Node *head)
{
    Node *temp = head;
    int sum = 0;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        sum += temp->data;
        temp = temp->next;
    }
    return sum / cnt;
}

Tree *InsertTree(Tree *root, int x)
{
    if (root == NULL)
        return new Tree({x, nullptr, nullptr});
    if (x > root->data)
        root->right = InsertTree(root->right, x);
    else
        root->left = InsertTree(root->left, x);
    return root;
}

int Leaf(Tree *root)
{
    int cnt = 0;
    if (root == NULL)
        return 0;
    if (root->left == NULL || root->right == NULL)
        return 1;
    cnt += Leaf(root->left);
    cnt += Leaf(root->right);
    return cnt;
}

int main()
{
    Tree *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = InsertTree(root, x);
    }
    cout << Leaf(root) << endl;
}