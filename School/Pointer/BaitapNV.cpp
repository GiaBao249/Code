#include <bits/stdc++.h>
using namespace std;

struct Nhanvien
{
    string tenNv;
    int maNv;
    string phongBan;
    int hesoluong;
    int luongcoso;
    float thanhtien;
};

struct Node
{
    Nhanvien data;
    Node *next;
};

void Input(Node *&head)
{
    int n, i = 1;
    cout << "Nhap 1 de them nhan vien thu " << i << endl;
    cin >> n;
    while (n)
    {
        Node *newNhanvien = new Node();
        cout << "nhap ten nhan vien thu " << i << endl;
        cin >> newNhanvien->data.tenNv;
        cout << "nhap ma nhan vien thu " << i << endl;
        cin >> newNhanvien->data.maNv;
        cout << "nhap phong ban cua nhan vien thu " << i << endl;
        cin >> newNhanvien->data.phongBan;
        cout << "nhap he so luong cua nhan vien thu " << i << endl;
        cin >> newNhanvien->data.hesoluong;
        cout << "nhap luong co so cua nhan vien thu " << i << endl;
        cin >> newNhanvien->data.luongcoso;
        newNhanvien->next = NULL;
        if (head == NULL)
            head = newNhanvien;
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNhanvien;
        }
        i++;
        cout << "Ban co muon them nhan vien vao danh sach khong -> 1/0" << endl;
        cin >> n;
    }
}

void Output(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data.tenNv << "\t" << temp->data.maNv << "\t" << temp->data.phongBan
             << "\t" << temp->data.hesoluong << "\t" << temp->data.luongcoso << "\t" << temp->data.hesoluong * temp->data.luongcoso << endl;
        temp = temp->next;
    }
    cout << endl;
}

void PushFront(Node *&head)
{
    Node *newNode = new Node();
    cout << "nhap ten nhan vien " << endl;
    cin >> newNode->data.tenNv;
    cout << "nhap ma nhan vien " << endl;
    cin >> newNode->data.maNv;
    cout << "nhap phong ban cua nhan vien " << endl;
    cin >> newNode->data.phongBan;
    cout << "nhap he so luong cua nhan vien " << endl;
    cin >> newNode->data.hesoluong;
    cout << "nhap luong co so cua nhan vien " << endl;
    cin >> newNode->data.luongcoso;
    newNode->next = head;
    head = newNode;
}

void PushBack(Node *&head)
{
    Node *temp = head;
    Node *newNode = new Node();
    cout << "nhap ten nhan vien " << endl;
    cin >> newNode->data.tenNv;
    cout << "nhap ma nhan vien " << endl;
    cin >> newNode->data.maNv;
    cout << "nhap phong ban cua nhan vien " << endl;
    cin >> newNode->data.phongBan;
    cout << "nhap he so luong cua nhan vien " << endl;
    cin >> newNode->data.hesoluong;
    cout << "nhap luong co so cua nhan vien " << endl;
    cout << newNode->data.luongcoso;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertMid(Node *&head)
{
    Node *temp = head;
    int k = 0;
    while (temp->next != nullptr)
    {
        k++;
        temp = temp->next;
    }
    k /= 2;
    Node *newNhanvien = new Node();
    cout << "nhap ten nhan vien " << endl;
    cin >> newNhanvien->data.tenNv;
    cout << "nhap ma nhan vien " << endl;
    cin >> newNhanvien->data.maNv;
    cout << "nhap phong ban cua nhan vien " << endl;
    cin >> newNhanvien->data.phongBan;
    cout << "nhap he so luong cua nhan vien " << endl;
    cin >> newNhanvien->data.hesoluong;
    cout << "nhap luong co so cua nhan vien " << endl;
    cin >> newNhanvien->data.luongcoso;
    newNhanvien->next = NULL;
    Node *current = head;
    for (int i = 0; i < k - 2; i++)
    {
        current = current->next;
    }
    newNhanvien->next = current->next;
    current->next = newNhanvien;
}

void PopFront(Node *&head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

void PopBack(Node *&head)
{
    Node *temp = head;
    if (head == nullptr)
        return;

    if (temp->next == NULL)
    {
        head = nullptr;
        delete temp;
        return;
    }
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    Node *last = temp->next;
    temp->next = NULL;
    delete last;
}

void Delete(Node *&head, int k)
{
    int n = sizeof(head);
    if (k < 1 || k > n)
        return;
    if (k == 1)
    {
        PopFront(head);
        return;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i <= k - 2; i++)
            temp = temp->next;
        Node *kNode = temp->next;
        temp->next = kNode->next;
        delete kNode;
    }
}

void MoneySum(Node *head)
{
    Node *temp = head;
    long long sum = 0;
    while (temp->next != nullptr)
    {
        temp->data.thanhtien = temp->data.hesoluong * temp->data.luongcoso;
        sum += temp->data.thanhtien;
        temp = temp->next;
    }
    cout << "Tong luong cua nhan vien la : " << sum << endl;
}

int main()
{
    Node *head = nullptr;
    int choice;
    do
    {
        cout << "1.Input\n";
        cout << "2.InsertMid\n";
        cout << "3.Delete K Node\n";
        cout << "4.OutPut\n";
        cout << "5.PopBack\n";
        cout << "6.PopFront\n";
        cout << "7.MoneySum \n";
        cout << "8.PushPront \n";
        cout << "9.PushBack \n";
        cout << "0.Exit\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Input(head);
            break;
        case 2:
            InsertMid(head);
            break;
        case 3:
            int k;
            cout << "Nhap vi tri ban muon xoa : ";
            cin >> k;
            Delete(head, k);
            break;
        case 4:
            Output(head);
            break;
        case 5:
            PopBack(head);
            break;
        case 6:
            PopFront(head);
            break;
        case 7:
            MoneySum(head);
            break;
        case 8:
            PushFront(head);
            break;
        case 9:
            PushBack(head);
            break;
        case 0:
            cout << "Tam biet!";
            break;
        default:
            cout << "Khong hop le!";
            break;
        }
    } while (choice != 0);
    cout << endl;
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
