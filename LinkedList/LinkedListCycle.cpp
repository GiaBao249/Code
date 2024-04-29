#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

bool hasCycle(node *&head)
{
    if (head == NULL && head->next == NULL)
        return false;

    node *slow = head;
    node *fast = head->next;

    int step_Max = 2;
    while (slow != NULL)
    {
        int count = 0;
        while (fast != NULL)
        {
            if (fast == slow)
                return true;
            fast = fast->next;
            count++;
            if (count == step_Max)
                break;
        }
        slow = slow->next;
    }
    return false;
}

// Cách tối ưu hơn
bool hasCycle1(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return true;
    }

    return false;
}
