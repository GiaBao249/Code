#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *addTwoNumbers(ListNode *head1, ListNode *head2)
{
    ListNode *l1 = head1;
    ListNode *l2 = head2;
    ListNode *res = new ListNode(0);
    ListNode *cur = res;
    int cnt = 0;
    while (l1 != NULL || l2 != NULL || cnt)
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + cnt;
        cnt = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return res->next;
}