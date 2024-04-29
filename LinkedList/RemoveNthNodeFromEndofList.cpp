#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *curNode = head;
    ListNode *theWantedNode = NULL;
    int count = 1;
    while (curNode != nullptr)
    {

        if (count == n + 1)
        {
            theWantedNode = head;
        }

        if (curNode->next == NULL)
        {
            if (theWantedNode == NULL)
            {
                if (count == n)
                {
                    return head->next;
                }
                return head;
            }
            else if (theWantedNode != nullptr)
            {
                theWantedNode->next = theWantedNode->next->next;
                return head;
            }
        }
        ++count;
        curNode = curNode->next;
        theWantedNode = theWantedNode == nullptr ? nullptr : theWantedNode->next;
    }
    return head;
}