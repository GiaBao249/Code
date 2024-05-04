#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *runA = headA;
    ListNode *runB = headB;
    if (runA == runB)
        return runA;
    while (true)
    {
        if (runA != NULL)
            runA = runA->next;
        else
            runA = headB;
        if (runB != NULL)
            runB = runB->next;
        else
            runB = headA;
        if (runA == runB)
            return runA;
    }
    return nullptr;
}
