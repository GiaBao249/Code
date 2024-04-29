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

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *curNode = head;
    ListNode *prevNode = NULL;
    while (curNode != NULL)
    {
        bool ok = false;
        if (curNode->val == val)
        {
            if (prevNode == NULL)
            {
                head = curNode->next;
            }
            else
            {
                prevNode->next = curNode->next;
            }
            ok = true;
        }
        prevNode = ok == true ? prevNode : curNode;
        curNode = curNode->next;
    }
    return head;
}
