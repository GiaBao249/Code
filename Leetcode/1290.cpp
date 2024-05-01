#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};
int getDecimalValue1(ListNode *head)
{
    int res = 0;
    if (head == NULL)
        return 0;
    ListNode *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->val == 1)
        {
            res += pow(2, i - 1);
        }
        i--;
        temp = temp->next;
    }
    return res;
}

int getDecimalValue2(ListNode *head)
{
    int res = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        res = (res << 1) | temp->val;
        temp = temp->next;
    }
    return res;
}
