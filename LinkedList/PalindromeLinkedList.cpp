#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

int count(ListNode *head)
{
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *curNode = head;
    while (curNode != nullptr && curNode->next != nullptr)
    {
        ListNode *nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = head;
        head = nextNode;
    }
    return head;
}

bool isPalindrome(ListNode *head)
{
    int n = count(head);
    int k = n / 2;
    int index = 0;
    ListNode *curNode = head;
    while (curNode != nullptr)
    {
        if (index == (n % 2 == 0 ? k : (k + 1)))
        {
            break;
        }

        ++index;
        curNode = curNode->next;
    }

    ListNode *secondNode = reverseList(curNode);
    index = 0;
    while (index < k)
    {
        if (head->val != secondNode->val)
            return false;

        head = head->next;
        secondNode = secondNode->next;

        ++index;
    }
    return true;
}

int main()
{
    ListNode *head = NULL;
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(3);
    ListNode *a3 = new ListNode(1);
    a1->next = a2;
    a2->next = a3;
    cout << boolalpha << isPalindrome(a1) << endl;
    return 0;
}
