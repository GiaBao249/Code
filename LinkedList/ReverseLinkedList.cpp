#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *curNode = head;
//         while (curNode != NULL && curNode->next != NULL)
//         {
//             ListNode *nextNode = curNode->next;
//             curNode->next = nextNode->next;
//             nextNode->next = head;
//             head = nextNode;
//         }
//         return head;
//     }
// };

// Hàm tạo một nút mới cho danh sách liên kết
ListNode *newNode(int val, ListNode *next)
{
    ListNode *node = new ListNode();
    node->val = val;
    node->next = next;
    return node;
}

// Hàm in ra các giá trị của các nút trong danh sách liên kết
void printList(ListNode *head)
{
    ListNode *curNode = head;
    while (curNode != NULL)
    {
        cout << curNode->val << " ";
        curNode = curNode->next;
    }
    cout << endl;
}

// Hàm đảo ngược danh sách liên kết
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

// Hàm chính để kiểm tra hàm đảo ngược danh sách liên kết
int main()
{
    // Khởi tạo một danh sách liên kết
    ListNode *head = newNode(1, newNode(2, newNode(3, newNode(4, newNode(5, NULL)))));
    // In ra danh sách liên kết ban đầu
    cout << "Danh sach lien ket ban dau: ";
    printList(head);
    // Gọi hàm đảo ngược danh sách liên kết
    ListNode *reversedHead = reverseList(head);
    // In ra danh sách liên kết sau khi đảo ngược
    cout << "Danh sach lien ket sau khi dao nguoc: ";
    printList(reversedHead);
    return 0;
}
