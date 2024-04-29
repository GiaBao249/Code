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

ListNode *oddEvenList(ListNode *head)
{
    ListNode *curNode = head;
    ListNode *theLastOddNode = NULL;
    ListNode *theLastEvenNode = NULL;

    int index = 1;

    while (curNode != nullptr)
    {
        ListNode *nextNode = curNode->next;
        if (index == 1)
            theLastOddNode = curNode;
        else if (index == 2)
            theLastEvenNode = curNode;

        if (index > 2)
        {
            if (index % 2 != 0)
            {
                curNode->next = theLastOddNode->next;
                theLastOddNode->next = curNode;
                theLastEvenNode->next = nextNode;
            }
            else
            {
                theLastEvenNode = theLastEvenNode->next;
                theLastOddNode = theLastOddNode->next;
            }
        }

        ++index;
        curNode = nextNode;
    }
    return head;
}

void duyet(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << ' ';
        head = head->next;
    }
}

int main()
{
    ListNode *head = NULL;
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    a1->next = a2;
    a2->next = a3;
    oddEvenList(a1);
    duyet(a1);
    return 0;
}
