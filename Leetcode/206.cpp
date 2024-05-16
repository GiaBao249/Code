#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode reverseList(ListNode *&head)
{
    ListNode *cur = head;
    while (cur != NULL && cur->next != NULL)
    {
        ListNode *nextNode = cur->next;
        cur->next = nextNode->next;
        nextNode->next = head;
        head = nextNode;
    }
    return head;
}
// De quy
ListNode ReverseList(ListNode *&head)
{
    // THCS
    if (head == nullptr)
        return nullptr;
    ListNode *nextNode = head->next;
    if (nextNode == nullptr)
        return nextNode;
    // THTQ
    ListNode *newHead = ReverseList(nextNode);
    nextNode->next = head;
    head->next = NULL;
}