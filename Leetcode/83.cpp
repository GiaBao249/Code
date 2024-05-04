#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        if (head == NULL)
            return head;
        while (temp->next != NULL)
        {
            ListNode *nextNode = temp->next;
            if (temp->val == nextNode->val)
            {
                temp->next = nextNode->next;
            }
            else
                temp = temp->next;
        }
        return head;
    }
};