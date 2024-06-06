#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int top;
    int n;
    int a[100];
    Stack()
    {
        top = -1;
    }
};

bool empty(Stack &s)
{
    return s.top == -1;
}

void push(Stack &st, int x)
{
    st.top = st.top + 1;
    st.a[st.top] = x;
}

int pop(Stack &s)
{
    int val = s.a[s.top];
    s.top = s.top - 1;
    return val;
}
int Top(Stack &s)
{
    return s.a[s.top];
}

void Negative(Stack &s)
{
    Stack temp;
    while (!empty(s))
    {
        if (Top(s) >= 0)
            push(temp, Top(s));
        pop(s);
    }

    while (!empty(temp))
    {
        push(s, Top(temp));
        pop(temp);
    }
}

void print(Stack &s)
{
    while (!empty(s))
    {
        cout << Top(s) << " ";
        pop(s);
    }
}

struct Tree
{
    int data;
    Tree *left, *right;
    Tree(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Tree *insert(Tree *root, int x)
{
    if (root == NULL)
        return new Tree(x);
    if (x > root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left, x);
    return root;
}

void test(Tree *root, vector<int> &v)
{
    if (root == NULL || v.size() == 3)
        return;
    else
    {
        test(root->right, v);

        if (v.size() < 3)
            v.push_back(root->data);
        test(root->left, v);
    }
}
vector<int> getThreeLargest(Tree *root)
{
    vector<int> result;
    test(root, result);
    return result;
}

int a[3] = {0}, k = 0;

void Solve(Tree *T)
{
    if (!T || k == 3)
        return;
    Solve(T->left);
    if (k < 3)
        a[k++] = T->data;
    Solve(T->right);
}

struct Node
{
    int data;
    Node *next = NULL;
};

int count(Node *head)
{
    int cnt = 0;
    while (head)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void InsertList(Node *&head, int x, int k)
{
    Node *temp = head;
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (k == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    else if (k > count(head) + 1)
        return;
    else
    {
        temp = head;
        while (k > 2 && temp)
        {
            k--;
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void PopFront(Node *&head)
{
    if (!head)
        return;
    else
        head = head->next;
}

void PopBack(Node *&head)
{
    if (head == NULL)
        return;
    else if (head->next == NULL)
    {
        head = head->next;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void Erase(Node *&head, int k)
{
    Node *temp = head;
    if (!head)
        return;
    else if (k == 1)
    {
        head = head->next;
        delete temp;
        return;
    }
    else if (k > count(head) + 1)
        return;
    else
    {
        while (k > 2 && temp)
        {
            k--;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next;
    }
}

void PrintList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    InsertList(head, 1, 1);
    InsertList(head, 2, 2);
    InsertList(head, 3, 3);
    InsertList(head, 4, 2);

    Erase(head, 2);

    PrintList(head);

    return 0;
}