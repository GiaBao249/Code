#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
typedef struct CELL *LIST;
struct CELL
{
	int ID;
	char Name[20];
	int Num_In;
	int Num_Out;
	float Price_In;
	float Price_Out;
	LIST next;
};

void thongbao();
void menu(LIST &L, int &n);

void Y1();
void Y2(LIST &L);
void Y3(LIST &L);
void Y4(LIST &L);
void Y5(LIST &L);
void Y6(LIST &L);
void Y7(LIST &L);
void Y8(LIST &L);

int main()
{
	LIST L = NULL;
	int n = 1;
	while (n)
	{
		thongbao();
		cout << "Ban chon...";
		cin >> n;
		cin.ignore();
		menu(L, n);
	}
	return 0;
}
// Cuong
void Y1()
{
	fstream fo;
	int a, c, d;
	float e, f;
	char b[20];

	fo.open("D:\\data\\input.txt", ios::out | ios::binary);
	if (!fo)
	{
		cout << "Khong mo duoc file\n";
		return;
	}
	cout << "Nhap so luong mat hang: ";
	int n;
	cin >> n;
	cin.ignore();
	fo.write((char *)&n, sizeof(n));

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap mat hang thu " << i + 1 << endl;
		cout << "Nhap ma san pham: ";
		cin >> a;
		cin.ignore();
		cout << "Nhap ten san pham: ";
		cin.get(b, 20);
		cout << "Nhap so luong nhap: ";
		cin >> c;
		cin.ignore();
		cout << "Nhap so luong xuat: ";
		cin >> d;
		cin.ignore();
		cout << "Nhap don gia nhap: ";
		cin >> e;
		cin.ignore();
		cout << "Nhap don gia xuat: ";
		cin >> f;
		cin.ignore();
		fo.write((char *)&a, sizeof(a));
		fo.write(b, sizeof(b));
		fo.write((char *)&c, sizeof(c));
		fo.write((char *)&d, sizeof(d));
		fo.write((char *)&e, sizeof(e));
		fo.write((char *)&f, sizeof(f));
	}

	fo.close();
}
void cpydata_string(string &temp, char a[])
{
	temp = "";
	for (int i = 0; a[i] != '\0'; i++)
	{
		temp += a[i];
	}
}
void Insert(LIST &L, int a, char b[], int c, int d, float e, float f)
{
	LIST x = new (CELL);
	x->ID = a;
	strcpy(x->Name, b);
	x->Num_In = c;
	x->Num_Out = d;
	x->Price_In = e;
	x->Price_Out = f;
	x->next = L;
	L = x;
}
void Print(LIST L)
{
	cout << "Thong tin mat hang: \n";
	cout << left << setw(15) << "Ma sp" << setw(15) << "Ten sp" << setw(15) << "SL nhap" << setw(15) << "SL xuat" << setw(15) << "Don gia nhap" << setw(15) << "Don gia xuat" << setw(15) << "SL ton" << setw(15) << "So tien ton";
	cout << endl;

	LIST x = L;
	while (x != NULL)
	{
		string temp;
		cpydata_string(temp, x->Name);
		cout << left << setw(15) << x->ID << setw(15) << temp << setw(15) << x->Num_In << setw(15) << x->Num_Out << setw(15) << x->Price_In << setw(15) << x->Price_Out << setw(15) << x->Num_In - x->Num_Out << setw(15) << x->Num_Out * x->Price_Out - x->Num_In * x->Price_In;
		cout << endl;
		x = x->next;
	}
}
void Y2(LIST &L)
{
	if (L != NULL)
	{
		Print(L);
		return;
	}
	fstream fi;
	int n;
	int a, c, d;
	float e, f;
	char b[20];

	fi.open("D:\\data\\input.txt", ios::in | ios::binary);
	if (!fi)
	{
		cout << "Khong mo duoc file!\n";
		return;
	}

	fi.read((char *)&n, sizeof(n));
	for (int i = 0; i < n; i++)
	{
		fi.read((char *)&a, sizeof(a));
		fi.read(b, sizeof(b));
		fi.read((char *)&c, sizeof(c));
		fi.read((char *)&d, sizeof(d));
		fi.read((char *)&e, sizeof(e));
		fi.read((char *)&f, sizeof(f));
		Insert(L, a, b, c, d, e, f);
	}
	fi.close();
	Print(L);
}
void hv(LIST &x, LIST &y)
{
	swap(x->ID, y->ID);
	swap(x->Name, y->Name);
	swap(x->Num_In, y->Num_In);
	swap(x->Num_Out, y->Num_Out);
	swap(x->Price_In, y->Price_In);
	swap(x->Price_Out, y->Price_Out);
}
bool sosanh(char a[], char b[])
{
	for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++)
	{
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return 0;
	}
	return 0;
}
void Y3(LIST &L)
{
	LIST x = L;
	while (x != NULL)
	{
		LIST y = x->next;
		while (y != NULL)
		{
			if (strcmp(x->Name, y->Name) == 1)
				hv(x, y);
			y = y->next;
		}
		x = x->next;
	}
}
void Y4(LIST &L)
{
	string a;
	cout << "Nhap mat hang muon tim...";
	getline(cin, a);
	LIST x = L;
	while (x != NULL)
	{
		string temp;
		cpydata_string(temp, x->Name);
		if (temp == a)
		{
			cout << left << setw(15) << "Ma sp" << setw(15) << "Ten sp" << setw(15) << "SL nhap" << setw(15) << "SL xuat" << setw(15) << "Don gia nhap" << setw(15) << "Don gia xuat" << setw(15) << "SL ton" << setw(15) << "So tien ton";
			cout << left << setw(15) << x->ID << setw(15) << temp << setw(15) << x->Num_In << setw(15) << x->Num_Out << setw(15) << x->Price_In << setw(15) << x->Price_Out << setw(15) << x->Num_In - x->Num_Out << setw(15) << x->Num_Out * x->Price_Out - x->Num_In * x->Price_In;
			cout << endl;
		}
		x = x->next;
	}
}
// Bao
void Y5(LIST &L)
{
	int cnt = 0;
	LIST count = L;
	while (count != NULL)
	{
		cnt++;
		count = count->next;
	}
	cout << "Ban muon them vi tri nao..." << endl;
	int n;
	cin >> n;
	LIST temp = L;
	LIST newBook = new CELL;
	cout << "Nhap id ";
	cin >> newBook->ID;
	cout << "Nhap name ";
	cin.ignore();
	cin.get(newBook->Name, 20);
	cout << "Nhap luong nhap ";
	cin >> newBook->Num_In;
	cout << "Nhap luong xuat ";
	cin >> newBook->Num_Out;
	cout << "Nhap Gia nhap ";
	cin >> newBook->Price_In;
	cout << "Nhap Gia xuat ";
	cin >> newBook->Price_Out;
	if (n == 1) // them vao dau danh sach
	{
		newBook->next = L;
		L = newBook;
		return;
	}
	if (n > cnt) // tu dong them vao cuoi
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newBook;
		return;
	}
	for (int i = 1; i <= n - 2; i++)
	{
		temp = temp->next;
	}
	newBook->next = temp->next;
	temp->next = newBook;
}
void Y6(LIST &L)
{
	int cnt = 0;
	LIST count = L;
	while (count != NULL)
	{
		cnt++;
		count = count->next;
	}
	int n;
	cout << "Nhap ma sach ban muon xoa...";
	cin >> n;
	LIST temp = L;
	LIST prev = nullptr;
	if (n == 1) // xoa o  dau danh sach
	{
		L = L->next;
		delete temp;
		return;
	}
	else if (n > cnt) // tu dong xoa vao cuoi
	{
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		delete temp;
		return;
	}
	else
	{
		while (temp->next != NULL)
		{
			LIST nextNode = temp->next;
			if (temp->next->ID == n)
			{
				temp->next = nextNode->next;
			}
			else
				temp = temp->next;
		}
	}
}
void Y7(LIST &L)
{
	int n;
	do
	{
		cout << "1.Ban muon them san pham ?" << endl;
		cout << "2.Ban muon giam san pham ?" << endl;
		cout << "3.Ban muon thay doi gia san pham ?" << endl;
		cout << "0.De Thoat" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			LIST temp = L;
			cout << "Moi ban nhap ma sach de thay doi :";
			int m;
			cin >> m;
			cout << "Ban mun tang so luong len bao nhieu san pham :";
			int num;
			cin >> num;
			while (temp != NULL)
			{
				if (temp->ID == m)
				{
					temp->Num_In = (temp->Num_In + num);
					temp->Price_In = (temp->Num_In + num) * temp->Price_In;
					break;
				}
				temp = temp->next;
			}
			cout << "Thanh cong !" << endl;
			break;
		}
		case 2:
		{
			LIST temp = L;
			cout << "Moi ban nhap ma sach de thay doi :";
			int m;
			cin >> m;
			cout << "Ban mun giam so luong xuong bao nhieu san pham :";
			int num;
			cin >> num;
			while (temp != NULL)
			{
				if (temp->ID == m)
				{
					temp->Num_In = (temp->Num_In - num);
					temp->Price_In = (temp->Num_In - num) * temp->Price_In;
					break;
				}
				temp = temp->next;
			}
			cout << "Thanh cong !" << endl;
			break;
		}
		case 3:
		{
			LIST temp = L;
			cout << "Moi ban nhap ma sach de thay doi :";
			int m;
			cin >> m;
			cout << "Ban muon thay doi so tien thanh bao nhieu :";
			float num;
			cin >> num;
			while (temp != NULL)
			{
				if (temp->ID == m)
				{
					temp->Price_Out = num;
					break;
				}
				temp = temp->next;
			}
			cout << "Thanh cong !" << endl;
			break;
		}
		default:
			break;
		}
	} while (n != 0);
}
void Y8(LIST &L)
{
	int cnt = 0;
	LIST count = L;
	while (count != NULL)
	{
		cnt++;
		count = count->next;
	}

	ofstream fs("D:\\data\\input.txt", ios::binary);
	if (!fs.is_open())
		return;
	else
	{
		fs.write((char *)&cnt, sizeof(cnt));
		LIST temp = L;
		while (temp != NULL)
		{
			int a, c, d;
			char b[20];
			float e, f;
			a = temp->ID;
			strcpy(b, temp->Name);
			c = temp->Num_In;
			d = temp->Num_Out;
			e = temp->Price_In;
			f = temp->Price_Out;
			fs.write((char *)&a, sizeof(a));
			fs.write(b, sizeof(b));
			fs.write((char *)&c, sizeof(c));
			fs.write((char *)&d, sizeof(d));
			fs.write((char *)&e, sizeof(e));
			fs.write((char *)&f, sizeof(f));
			temp = temp->next;
		}
	}
	fs.close();
}
// Phan main
void thongbao()
{
	cout << "-------------------------------------------------------\n";
	cout << "Chon 0: Thoat\n";
	cout << "Chon 1: Nhap danh sach mat hang\n";
	cout << "Chon 2: In danh sach san pham\n";
	cout << "Chon 3: Sap xep danh sach theo thu tu tang dan\n";
	cout << "Chon 4: Tim thong tin sach\n";
	cout << "Chon 5: Them mot cuon sach\n";
	cout << "Chon 6: xoa mot cuon sach\n";
	cout << "Chon 7: Cap nhat thong tin cuon sach theo ma sp\n";
	cout << "Chon 8: Luu lai danh sach vao file\n";
	cout << "-------------------------------------------------------\n";
}
void menu(LIST &L, int &n)
{
	switch (n)
	{
	case 0:
		break;
	case 1:
		Y1();
		break;
	case 2:
		Y2(L);
		break;
	case 3:
		Y3(L);
		break;
	case 4:
		Y4(L);
		break;
	case 5:
		Y5(L);
		break;
	case 6:
		Y6(L);
		break;
	case 7:
		Y7(L);
		break;
	case 8:
		Y8(L);
		break;
	}
	return;
}
/*
1
10
1
c
0
0
0
0
2
d
0
0
0
0
3
a
0
0
0
0
4
b
0
0
0
0
5
g
0
0
0
0
6
i
0
0
0
0
7
h
0
0
0
0
8
ad
0
0
0
0
9
nm
0
0
0
0
10
c
0
0
0
0

*/