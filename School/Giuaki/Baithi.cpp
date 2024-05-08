#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    string name;
    int amountIn;
    int amountOut;
    int pieceIn;
    int pieceOut;
    double Money;
    double amountReduce;

    double UpdateMoney()
    {
        Money = pieceOut * amountOut;
        return Money;
    }
    double UpdateAmountReduce()
    {
        amountReduce = amountIn - amountOut;
        return amountReduce;
    }
    Node *next;
};

void ReadFile(string &file, Node *&book)
{
    ifstream fs(file, ios::binary);
    if (!fs.is_open())
        return;
    else
    {
        while (!fs.eof())
        {
            Node *temp = new Node();
            fs >> temp->id >> temp->name >> temp->amountIn >> temp->amountOut >> temp->pieceIn >> temp->pieceOut;
            temp->UpdateAmountReduce();
            temp->UpdateMoney();

            temp->next = book;
            book = temp;
        }
    }
    fs.close();
}

void WriteFile(string &file, Node *book)
{
    ofstream fs(file, ios::binary);
    if (!fs.is_open())
        return;
    else
    {
        Node *temp = book;
        while (temp != nullptr)
        {
            fs << temp->id << " " << temp->name << " " << temp->amountIn << " " << temp->amountOut << " " << temp->pieceIn << " " << temp->pieceOut;
            temp = temp->next;
        }
    }
    fs.close();
}

void PushBook(Node *&head)
{
    Node *newBook = new Node();
    cout << "Nhập mã sách: ";
    cin >> newBook->id;
    cout << "Nhập tên sách: ";
    cin.ignore();
    getline(cin, newBook->name);
    cout << "Nhập số lượng nhập: ";
    cin >> newBook->amountIn;
    cout << "Nhập số lượng xuất: ";
    cin >> newBook->amountOut;
    cout << "Nhập đơn giá nhập: ";
    cin >> newBook->pieceIn;
    cout << "Nhập đơn giá xuất: ";
    cin >> newBook->pieceOut;

    newBook->Money = newBook->UpdateMoney();
    newBook->amountReduce = newBook->UpdateAmountReduce();
    if (head == NULL)
    {
        head = newBook;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

void Print(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Kho trống vui lòng thêm sách";
        return;
    }
    while (temp != NULL)
    {
        cout << "Mã sách: " << temp->id << endl;
        cout << "Tên sách: " << temp->name << endl;
        cout << "Số lượng nhập: " << temp->amountIn << endl;
        cout << "Số lượng xuất: " << temp->amountOut << endl;
        cout << "Đơn giá nhập: " << temp->pieceIn << endl;
        cout << "Đơn giá xuất: " << temp->pieceOut << endl;
        cout << "Số lượng tồn: " << temp->UpdateAmountReduce() << endl;
        cout << "Số tiền tồn: " << temp->UpdateMoney() << endl;
        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    string file = "test.txt";
    Node *head = NULL;
    int choice;
    ReadFile(file, head);
    do
    {
        cout << "----------- Menu -----------" << endl;
        cout << "1. In danh sách sản phẩm" << endl;
        cout << "2. Sắp xếp danh sách theo tên" << endl;
        cout << "3. Tìm kiếm và in thông tin sách" << endl;
        cout << "4. Thêm sách mới" << endl;
        cout << "5. Xóa sách" << endl;
        cout << "0. Thoát" << endl;
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (head == NULL)
            {
                cout << "không có sách" << endl;
                break;
            }
            else
                Print(head);
            break;
        }
        case 2:
        {
            PushBook(head);
            break;
        }
        default:
            break;
        }
        WriteFile(file, head);
    } while (choice != 0);

    return 0;
}
