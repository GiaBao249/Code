#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int checkNode(ListNode *curNode)
    {

        if (curNode == NULL)
            return -1;

        ListNode *slow = curNode;
        ListNode *fast = curNode;
        while (slow != NULL && fast->next != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                if (fast == curNode)
                    return 1;
                return 0;
            }
        }

        return -1;
    };

public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *curNode = head;

        while (curNode != NULL)
        {
            int result = checkNode(curNode);
            if (result == -1)
                return NULL;
            else if (result == 1)
                return curNode;
            else
            {
                curNode = curNode->next;
            }
        }
        return NULL;
    }
};

// cách tối ưu

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                ListNode *start = head;
                while (start != slow)
                {
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
        }

        return NULL;
    }
};
