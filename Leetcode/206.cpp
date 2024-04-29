using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode reverseList(ListNode *&head)
{
    ListNode *cur = head;
    while (cur != NULL && cur->next != NULL)
    {
        ListNode *nextNode = cur->next;
        cur->next = nextNode->next;
        nextNode->next = head;
        head = nextNode;
    }
    return head;
}
// De quy
ListNode reverseList(ListNode *&head)
{
    // THCS
    if (head == nullptr)
        return null;
    ListNode *nextNode = head->next;
    if (nextNode == null)
        return nextNode;
    // THTQ
    ListNode *newHead = reverseList(nextNode);
    nextNode->next = head;
    head->next = NULL;
}