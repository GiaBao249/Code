#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Struct chứa thông tin của sản phẩm
struct Product
{
    string code;      // Mã sản phẩm
    string name;      // Tên sản phẩm
    int quantity;     // Số lượng
    float price;      // Đơn giá
    float totalPrice; // Thành tiền (số lượng * đơn giá)

    // Hàm cập nhật thành tiền
    void updateTotalPrice()
    {
        totalPrice = quantity * price;
    }
};

struct ProductList
{
    vector<Product> products;
};

// Hàm nhập thông tin sản phẩm từ người dùng
Product inputProduct()
{
    Product product;
    cout << "Nhap ma san pham: ";
    cin >> product.code;
    cout << "Nhap ten san pham: ";
    cin.ignore();
    getline(cin, product.name);
    cout << "Nhap so luong: ";
    cin >> product.quantity;
    cout << "Nhap don gia: ";
    cin >> product.price;
    product.updateTotalPrice();
    return product;
}

// Hàm in thông tin của một sản phẩm
void printProduct(const Product &product)
{
    cout << setw(10) << product.code << setw(20) << product.name << setw(10) << product.quantity << setw(15) << product.price << setw(15) << product.totalPrice << endl;
}

// Hàm ghi một sản phẩm vào file nhị phân
void saveProductToFile(const string &fileName, const ProductList &Products)
{
    ofstream file(fileName, ios::binary); // Không cần mở file ở chế độ append
    if (!file.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }
    for (auto &it : Products.products)
    {
        file.write(reinterpret_cast<const char *>(&it), sizeof(it));
    }
    file.close();
}
// Hàm đọc và in danh sách sản phẩm từ file nhị phân ra màn hình
void readAndPrintProductsFromFile(const string &fileName)
{
    ifstream file(fileName, ios::binary); // Mở file ở chế độ nhị phân
    if (!file.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }

    cout << setw(10) << "Ma SP" << setw(20) << "Ten SP" << setw(10) << "SL" << setw(15) << "Don gia" << setw(15) << "Thanh tien" << endl;

    // Đọc dữ liệu từ file theo từng cấu trúc Product và in ra màn hình
    Product product;
    while (file.read(reinterpret_cast<char *>(&product), sizeof(product)))
    {
        printProduct(product);
    }

    file.close();
}

// Hàm tìm kiếm và in thông tin các sản phẩm theo tên từ file nhị phân ra màn hình
void searchAndPrintProductsByName(const string &fileName, const string &keyword)
{
    ifstream file(fileName, ios::binary);
    if (!file.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }
    Product product;
    bool found = false;
    cout << setw(10) << "Ma SP" << setw(20) << "Ten SP" << setw(10) << "SL" << setw(15) << "Don gia" << setw(15) << "Thanh tien" << endl;
    while (file.read(reinterpret_cast<char *>(&product), sizeof(product)))
    {
        if (product.name.find(keyword) != string::npos)
        {
            printProduct(product);
            found = true;
        }
    }
    if (!found)
    {
        cout << "Khong tim thay san pham nao co ten chua '" << keyword << "'" << endl;
    }
    file.close();
}

// Hàm thêm một sản phẩm vào file nhị phân
void addProductToFile(const string &fileName, const Product &product, ProductList &products)
{
    products.products.push_back(product);
    saveProductToFile(fileName, products);
}
// Hàm xóa một sản phẩm từ file nhị phân
void deleteProductFromFile(const string &fileName, const string &code)
{
    ifstream inFile(fileName, ios::binary);
    if (!inFile.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }

    ofstream outFile("temp.bin", ios::binary);
    if (!outFile.is_open())
    {
        cerr << "Khong tao duoc file tam." << endl;
        inFile.close();
        return;
    }

    Product product;
    bool found = false;
    while (inFile.read(reinterpret_cast<char *>(&product), sizeof(product)))
    {
        if (product.code != code)
        {
            outFile.write(reinterpret_cast<const char *>(&product), sizeof(product));
        }
        else
        {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove(fileName.c_str());
    rename("temp.bin", fileName.c_str());

    if (found)
    {
        cout << "Da xoa san pham co ma " << code << endl;
    }
    else
    {
        cout << "Khong tim thay san pham co ma " << code << endl;
    }
}

// Hàm cập nhật thông tin của một sản phẩm trong file nhị phân
void updateProductInFile(const string &fileName, const Product &newProduct)
{
    ifstream inFile(fileName, ios::binary);
    if (!inFile.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }

    ofstream outFile("temp.bin", ios::binary);
    if (!outFile.is_open())
    {
        cerr << "Khong tao duoc file tam." << endl;
        inFile.close();
        return;
    }

    Product product;
    bool found = false;
    while (inFile.read(reinterpret_cast<char *>(&product), sizeof(product)))
    {
        if (product.code == newProduct.code)
        {
            outFile.write(reinterpret_cast<const char *>(&newProduct), sizeof(newProduct));
            found = true;
        }
        else
        {
            outFile.write(reinterpret_cast<const char *>(&product), sizeof(product));
        }
    }

    inFile.close();
    outFile.close();

    remove(fileName.c_str());
    rename("temp.bin", fileName.c_str());

    if (found)
    {
        cout << "Da cap nhat san pham co ma " << newProduct.code << endl;
    }
    else
    {
        cout << "Khong tim thay san pham co ma " << newProduct.code << endl;
    }
}

int main()
{
    string fileName = "Shoppe.bin";
    int choice;
    ProductList productList;
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
            Product product = inputProduct();
            productList.products.push_back(product);
            saveProductToFile(fileName, productList);
            break;
        }
        case 2:
        {
            readAndPrintProductsFromFile(fileName);
            break;
        }
        case 3:
        {
            string keyword;
            cout << "Nhap ten san pham hoac tu khoa: ";
            cin.ignore(); // Để loại bỏ kí tự '\n' trong buffer
            getline(cin, keyword);
            searchAndPrintProductsByName(fileName, keyword);
            break;
        }
        case 4:
        {
            // Chưa triển khai chức năng này
            cout << "Chuc nang chua duoc trien khai." << endl;
            break;
        }
        case 5:
        {
            string code;
            cout << "Nhap ma san pham can xoa: ";
            cin >> code;
            deleteProductFromFile(fileName, code);
            break;
        }
        case 6:
        {
            Product newProduct = inputProduct();
            updateProductInFile(fileName, newProduct);
            break;
        }
        case 7:
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
