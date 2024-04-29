#include <bits/stdc++.h>
using namespace std;

struct Shoppe
{
    string id;
    string name;
    double price;
    double amount;
    double money;
    void UpdateMoney()
    {
        money = amount * price;
    }
};

struct ItemList
{
    vector<Shoppe> List;
};

Shoppe InputItems()
{
    Shoppe product;
    cout << "Nhap ma san pham: ";
    cin >> product.id;
    cout << "Nhap ten san pham: ";
    cin.ignore();
    getline(cin, product.name);
    cout << "Nhap so luong: ";
    cin >> product.amount;
    cout << "Nhap don gia: ";
    cin >> product.price;
    product.UpdateMoney();
    return product;
}

void printProduct(const Shoppe &product)
{
    cout << setw(5) << product.id << setw(20) << product.name << setw(20) << product.amount << setw(20) << product.price << setw(20) << product.money << endl;
}

void readAndPrint(const string &fileName)
{
    ifstream file(fileName, ios::binary);
    if (!file.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }

    cout << setw(10) << "Ma SP" << setw(20) << "Ten SP" << setw(20) << "SL" << setw(20) << "Don gia" << setw(20) << "Thanh tien" << endl;

    Shoppe product;
    while (file.read(reinterpret_cast<char *>(&product), sizeof(product)))
    {
        cout << setw(10) << product.id << setw(20) << product.name << setw(20) << product.amount << setw(20) << product.price << setw(20) << product.money << endl;
    }
    file.close();
}

void saveProductToFile(const string &fileName, const ItemList &Products)
{
    ofstream file(fileName, ios::binary);
    if (!file.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }
    for (auto &it : Products.List)
    {
        file.write(reinterpret_cast<const char *>(&it), sizeof(it));
    }
    file.close();
}

void seachItems(string &fileName, string &key)
{
    ifstream fs(fileName, ios::binary);
    if (!fs.is_open())
        return;
    bool ok = false;
    Shoppe product;
    while (fs.read(reinterpret_cast<char *>(&product), sizeof(product)))
    {
        if (product.name.find(key) != string ::npos)
        {
            ok = true;
            cout << setw(10) << "Ma SP" << setw(20) << "Ten SP" << setw(20) << "SL" << setw(20) << "Don gia" << setw(20) << "Thanh tien" << endl;
            printProduct(product);
        }
    }
    fs.close();
    if (!ok)
        cout << "Khong tim thay san pham ban tim !" << endl;
}

void addProduct(ItemList &items, Shoppe &product, string &fileName)
{
    items.List.push_back(product);
    saveProductToFile(fileName, items);
}

void deleteItems(string &fileName, string &id)
{
    ifstream fs(fileName, ios::binary);
    ofstream ofs("temp.bin", ios::binary);
    if (!fs.is_open() || !ofs.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }
    else
    {
        Shoppe product;
        bool ok = false;
        while (fs.read(reinterpret_cast<char *>(&product), sizeof(product)))
        {
            if (product.id.find(id) == string ::npos)
            {
                ok = true;
                ofs.write(reinterpret_cast<const char *>(&product), sizeof(product));
            }
        }
        fs.close();
        ofs.close();
        remove(fileName.c_str());
        rename("temp.bin", fileName.c_str());
        if (ok)
            cout << "Da xoa san pham !" << endl;
        else
            cout << "Khong tim thay id !" << endl;
    }
}

void ChangeItems(string &fileName, Shoppe &newProduct)
{
    ifstream fs(fileName, ios::binary);
    ofstream ofs("temp.bin", ios::binary);
    if (!fs.is_open() || !ofs.is_open())
        return;
    else
    {
        Shoppe product;
        bool ok = false;
        while (fs.read(reinterpret_cast<char *>(&product), sizeof(product)))
        {
            if (product.id == newProduct.id)
            {
                ok = true;
                ofs.write(reinterpret_cast<char *>(&newProduct), sizeof(newProduct));
            }
            else
            {
                ofs.write(reinterpret_cast<char *>(&product), sizeof(product));
            }
        }
        fs.close();
        ofs.close();
        remove(fileName.c_str());
        rename("temp.bin", fileName.c_str());
    }
}

int main()
{
    string fileName = "Shoppe.txt";
    int choice;
    ItemList items;
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Them san pham" << endl;
        cout << "2. In danh sach san pham" << endl;
        cout << "3. Tim kiem san pham theo ten" << endl;
        cout << "4. Them san pham vao vi tri bat ky" << endl;
        cout << "5. Xoa san pham" << endl;
        cout << "6. Cap nhat thong tin san pham" << endl;
        cout << "7. Thoat" << endl;
        cout << "Chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Shoppe product = InputItems();
            items.List.push_back(product);
            saveProductToFile(fileName, items);
            break;
        }
        case 2:
        {
            readAndPrint(fileName);
            break;
        }
        case 3:
        {
            string keyword;
            cout << "Nhap ten san pham hoac tu khoa: ";
            cin.ignore();
            getline(cin, keyword);
            seachItems(fileName, keyword);
            break;
        }
        case 4:
        {
            string code;
            cout << "Nhap ma san pham can xoa: ";
            cin >> code;
            deleteItems(fileName, code);
            break;
        }
        case 5:
        {
            Shoppe product = InputItems();
            ChangeItems(fileName, product);
            break;
        }
        case 6:
        {
            cout << "Ket thuc chuong trinh." << endl;
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
        }
    } while (choice != 7);
    return 0;
}