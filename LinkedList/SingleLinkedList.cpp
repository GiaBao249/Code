#include <iostream>
using namespace std;

// Kieu node
struct node
{
	int data;
	node *next;
};

// Tao 1 node
node *makeNode(int x)
{
	node *newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

// duyet mot danh sach lien ket
void duyet(node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

// Dem so luong node
int count(node *head)
{
	int dem = 0;
	while (head != NULL)
	{
		++dem;
		head = head->next;
	}
	return dem;
}

// them node vao dau danh sach
// C
void pushFrontC(node **head, int data)
{
	node *newNode = makeNode(data);
	newNode->next = *head;
	*head = newNode;
}

// C++
void pushFront(node *&head, int data)
{
	node *newNode = makeNode(data);
	newNode->next = head;
	head = newNode;
}

// them mot node o cuoi danh sach
void PushBack(node *&head, int data)
{
	node *temp = head;
	node *newNode = makeNode(data);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

// Them mot node vao giua
void insert(node *&head, int k, int data)
{
	int n = sizeof(head);
	if (k < 1 || k > n + 1)
		return;
	if (k == 1)
	{
		pushFront(head, data);
		return;
	}
	node *temp = head;
	for (int i = 1; i <= k - 2; i++)
	{
		temp->next = temp;
	}
	// temp = k - 1

	node *newNode = makeNode(data);
	newNode->next = temp->next;
	temp->next = newNode;
}

// Xoa node dau tien trong danh sach
void PopPront(node *&head)
{
	if (head == NULL)
		return;

	node *temp = head;
	head = head->next;
	delete temp;
}

// Xoa node cuoi cung
void PopBack(node *head)
{
	if (head == NULL)
		return;

	node *temp = head;
	if (temp->next == NULL)
	{
		head = NULL;
		delete temp;
		return;
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	node *last = temp->next; // node cuoi cung
	temp->next = NULL;
	delete last;
}

void Erase(node *&head, int k)
{
	int n = sizeof(head);
	if (k < 1 || k > n)
		return;
	if (k == 1)
	{
		PopPront(head);
		return;
	}
	else
	{
		node *temp = head;
		for (int i = 1; i <= k - 2; i++)
		{
			temp = temp->next; // chay cho den k - 1 thi dung lai
		}
		node *kNode = temp->next; // vi tri cua k
		temp->next = kNode->next;
		delete kNode;
	}
}

//----------------------------------------------------------------//
// Tao ngăn xếp bằng array
// st[10001] int n = 0;

// void pushArray(int x)
// {
// 	stack[n] = x;
// 	++n;
// }

// void PopArray()
// {
// 	if (n >= 1)
// 	{
// 		--n;
// 	}
// }

// void TopArray()
// {
// 	if (n == 0)
// 		return;
// 	return stack[n - 1];
// }

// void sizeArray()
// {
// 	return n;
// }

// //-------------------------------------------------------------------------------
// // Tạo ngăn xếp bằng LiskedList

// struct node
// {
// 	int data;
// 	node *next;
// };

// node *makeNode(int data)
// {
// 	node *newNode = new node();
// 	newNode->data = x;
// 	newNode->next = NULL;

// 	return newNode;
// }

// void PushLK(node *&top, int data)
// {
// 	node *newNode = makeNode(data);
// 	if (top == NULL)
// 	{
// 		top = newNode;
// 		return;
// 	}
// 	newNode->next = top;
// 	top = newNode;
// }

// void PopLK(node *&top)
// {
// 	if (top != NULL)
// 	{
// 		node *temp = top;
// 		top = temp->next;
// 		delete temp;
// 	}
// }

// void TopLK(node *&top)
// {
// 	if (top != NULL)
// 		return top->data;
// }

// int sizeLK(node *&top)
// {
// 	int ans = 0;
// 	while (top != NULL)
// 	{
// 		++ans;
// 		top = top->next;
// 	}
// 	return ans;
// }

// Queue trong Linkedlist
// Push : them mot phan tu O cuoi hang doi
// Pop : xoa 1 phan tu o dau hang doi

// struct node
// {
// 	int data;
// 	node *next;
// };

// node makeNode(int x)
// {
// 	node *newNode = new node();
// 	newNode->data = x;
// 	newNode->next = NULL;
// 	return newNode;
// }

// void PushQueue(node *&queue, int x)
// {
// 	node *newNode = makeNode(x);
// 	if (queue == NULL)
// 	{
// 		queue = newNode;
// 	}
// 	else
// 	{
// 		node *temp = queue;
// 		whie(temp->next != NULL)
// 		{
// 			temp = temp->next;
// 		}
// 		temp->next = newNode;
// 	}
// }

// void PopQueue(node *&queue)
// {
// 	if (queue == NULL)
// 		return;
// 	else
// 	{
// 		node *temp = queue;
// 		queue = queue->next;
// 		delete temp;
// 	}
// }

// int size(node *&queue)
// {
// 	if (queue == NULL)
// 		return 0;
// 	else
// 	{
// 		int ans = 0;
// 		while (queue != NULL)
// 		{
// 			++ans;
// 			queue = queue->next;
// 		}
// 	}
// 	return ans;
// }

// bool isEmpty(node *&queue)
// {
// 	return queue == NULL;
// }

// int front(node *&queue)
// {
// 	return queue->data;
// }

// void DuyetNode(node *&queue)
// {
// 	while (queue != NULL)
// 	{
// 		cout << queue->data << ' ';
// 		queue = queue->next;
// 	}
// }
