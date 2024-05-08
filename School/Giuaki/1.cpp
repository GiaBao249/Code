#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Khai báo cấu trúc thông tin sách
struct Book
{
    int id;
    string name;
    int quantityIn;
    int quantityOut;
    int priceIn;
    int priceOut;
    int quantityRemain;
    int moneyRemain;
    Book *next;
};

// Hàm nhập thông tin sách từ tệp tin
void ReadFile(Book *&head, string fileName)
{
    ifstream file(fileName, ios::binary);
    if (!file.is_open())
    {
        cout << "Không thể mở tệp tin." << endl;
        return;
    }

    while (!file.eof())
    {
        Book *newBook = new Book();
        file >> newBook->id >> newBook->name >> newBook->quantityIn >> newBook->quantityOut >> newBook->priceIn >> newBook->priceOut;

        newBook->quantityRemain = newBook->quantityIn - newBook->quantityOut;
        newBook->moneyRemain = newBook->quantityRemain * newBook->priceIn;

        // Thêm sách vào đầu danh sách liên kết
        newBook->next = head;
        head = newBook;
    }

    file.close();
}

// Hàm in danh sách sách ra màn hình
void PrintList(Book *head)
{
    Book *current = head;
    while (current != nullptr)
    {
        cout << "Mã sách: " << current->id << endl;
        cout << "Tên sách: " << current->name << endl;
        cout << "Số lượng nhập: " << current->quantityIn << endl;
        cout << "Số lượng xuất: " << current->quantityOut << endl;
        cout << "Đơn giá nhập: " << current->priceIn << endl;
        cout << "Đơn giá xuất: " << current->priceOut << endl;
        cout << "Số lượng tồn: " << current->quantityRemain << endl;
        cout << "Số tiền còn: " << current->moneyRemain << endl;
        cout << endl;
        current = current->next;
    }
}

// Hàm sắp xếp danh sách theo thứ tự tên sách (tăng dần)
void SortList(Book *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Book *sortedList = nullptr;
    Book *current = head;

    while (current != nullptr)
    {
        Book *nextNode = current->next;

        // Chèn current vào sortedList
        if (sortedList == nullptr || current->name < sortedList->name)
        {
            current->next = sortedList;
            sortedList = current;
        }
        else
        {
            Book *temp = sortedList;
            while (temp->next != nullptr && temp->next->name < current->name)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    head = sortedList;
}

// Hàm tìm kiếm sách theo tên
void SearchBookByName(Book *head, string name)
{
    Book *current = head;
    bool found = false;
    while (current != nullptr)
    {
        if (current->name == name)
        {
            found = true;
            cout << "Sách được tìm thấy:" << endl;
            cout << "Mã sách: " << current->id << endl;
            cout << "Tên sách: " << current->name << endl;
            cout << "Số lượng nhập: " << current->quantityIn << endl;
            cout << "Số lượng xuất: " << current->quantityOut << endl;
            cout << "Đơn giá nhập: " << current->priceIn << endl;
            cout << "Đơn giá xuất: " << current->priceOut << endl;
            cout << "Số lượng tồn: " << current->quantityRemain << endl;
            cout << "Số tiền còn: " << current->moneyRemain << endl;
            cout << endl;
        }
        current = current->next;
    }
    if (!found)
    {
        cout << "Không tìm thấy sách có tên \"" << name << "\"." << endl;
    }
}

// Hàm thêm sách mới vào danh sách
void AddBook(Book *&head)
{
    Book *newBook = new Book();
    cout << "Nhập mã sách: ";
    cin >> newBook->id;
    cout << "Nhập tên sách: ";
    cin.ignore();
    getline(cin, newBook->name);
    cout << "Nhập số lượng nhập: ";
    cin >> newBook->quantityIn;
    cout << "Nhập số lượng xuất: ";
    cin >> newBook->quantityOut;
    cout << "Nhập đơn giá nhập: ";
    cin >> newBook->priceIn;
    cout << "Nhập đơn giá xuất: ";
    cin >> newBook->priceOut;

    newBook->quantityRemain = newBook->quantityIn - newBook->quantityOut;
    newBook->moneyRemain = newBook->quantityRemain * newBook->priceIn;

    // Thêm sách mới vào đầu danh sách liên kết
    newBook->next = head;
    head = newBook;

    cout << "Sách đã được thêm vào danh sách." << endl;
}

// Hàm xóa sách khỏi danh sách
void DeleteBook(Book *&head, int id)
{
    if (head == nullptr)
    {
        cout << "Danh sách rỗng." << endl;
        return;
    }

    if (head->id == id)
    {
        Book *temp = head;
        head = head->next;
        delete temp;
        cout << "Sách đã được xóa khỏi danh sách." << endl;
        return;
    }

    Book *current = head;
    while (current->next != nullptr && current->next->id != id)
    {
        current = current->next;
    }

    if (current->next == nullptr)
    {
        cout << "Không tìm thấy sách có mã \"" << id << "\"." << endl;
        return;
    }

    Book *temp = current->next;
    current->next = current->next->next;
    delete temp;
    cout << "Sách đã được xóa khỏi danh sách." << endl;
}

int main()
{
    Book *head = nullptr;
    string fileName = "test.txt";

    // Đọc danh sách từ tệp tin
    ReadFile(head, fileName);

    int choice;
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
            cout << "----------- Danh sách sản phẩm -----------" << endl;
            PrintList(head);
            break;
        case 2:
            cout << "Sắp xếp danh sách theo tên sách..." << endl;
            SortList(head);
            cout << "Danh sách đã được sắp xếp." << endl;
            break;
        case 3:
        {
            string name;
            cout << "Nhập tên sách cần tìm: ";
            cin.ignore();
            getline(cin, name);
            SearchBookByName(head, name);
            break;
        }
        case 4:
            AddBook(head);
            break;
        case 5:
        {
            int id;
            cout << "Nhập mã sách cần xóa: ";
            cin >> id;
            DeleteBook(head, id);
            break;
        }
        }
    } while (choice != 0);

    // Giải phóng bộ nhớ khi kết thúc chương trình
    Book *current = head;
    while (current != nullptr)
    {
        Book *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
