#include <bits./stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *makeNode(int x)
{
    ListNode *newNode = new ListNode;
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

ListNode *ReverseList(ListNode *head)
{
    ListNode *curNode = head;
    while (curNode != NULL && curNode->next != NULL)
    {
        ListNode *nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = head;
        head = nextNode;
    }
    return head;
}

void PrintNode(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

void PushBack(ListNode *&head, int x)
{
    ListNode *temp = head;
    ListNode *newNode = makeNode(x);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

//! Stack
ListNode *removeNodes(ListNode *head)
{
    stack<ListNode *> st;
    ListNode *cur = head;
    while (cur != NULL)
    {
        while (!st.empty() && st.top()->val < cur->val)
            st.pop();
        st.push(cur);
        cur = cur->next;
    }
    ListNode *temp = nullptr;
    while (!st.empty())
    {
        cur = st.top();
        st.pop();
        cur->next = temp;
        temp = cur;
    }
    return cur;
}

//! Recursion

int main()
{
    ListNode *head = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        PushBack(head, x);
    }
    ListNode *temp = removeNodes(head);
    PrintNode(temp);
}