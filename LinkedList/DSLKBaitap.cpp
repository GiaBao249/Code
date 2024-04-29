#include <bits/stdc++.h>
using namespace std;

struct SinhVien
{
    string name;
    double gpa;
    SinhVien() {}
    SinhVien(string ten, double diem)
    {
        name = ten;
        gpa = diem;
    }
};
struct node
{
    SinhVien data;
    node *next;
};

node *makeNode(SinhVien s)
{
    node *newNode = new node;
    newNode->data = s;
    newNode->next = NULL;
    return newNode;
}

void PushBack(node *&head, SinhVien data)
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

// duyet mot danh sach lien ket
void duyet(node *head)
{
    while (head != NULL)
    {
        cout << head->data.name << ' ' << fixed << setprecision(2) << head->data.gpa << endl;
        head = head->next;
    }
}

void Sapxep1(node *&head)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        node *minHead = i;
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (minHead->data.gpa > j->data.gpa)
            {
                minHead = j;
            }
            else if (minHead->data.gpa == j->data.gpa)
            {
                if (minHead->data.name > j->data.name)
                {
                    minHead = j;
                }
            }
        }
        SinhVien temp = minHead->data;
        minHead->data = i->data;
        i->data = temp;
    }
}

int main()
{
    node *head = NULL;
    SinhVien s("Teo", 3.4);
    SinhVien v("Ti", 6.7);
    SinhVien t("Long", 8.1);
    SinhVien u("Bao", 6.7);
    PushBack(head, s);
    PushBack(head, v);
    PushBack(head, t);
    PushBack(head, u);
    Sapxep1(head);
    duyet(head);
}