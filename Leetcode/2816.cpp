#include <bits./stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

ListNode *reverseList(ListNode *head)
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

ListNode *doubleIt(ListNode *head)
{
    ListNode *temp = reverseList(head);
    int mod = 0;
    ListNode *cur = new ListNode(0);
    ListNode *res = cur;
    while (temp != NULL)
    {
        int sum = (temp->val * 2) + mod;
        mod = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (temp)
            temp = temp->next;
    }
    if (mod == 1)
    {
        cur->next = new ListNode(mod);
    }
    return reverseList(res->next);
}

int main()
{
    ListNode *head1 = new ListNode(9);
    head1->next = new ListNode(9);
    head1->next->next = new ListNode(9);

    ListNode *result = doubleIt(head1);
    while (result != NULL)
    {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}