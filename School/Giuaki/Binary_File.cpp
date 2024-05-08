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
}
void Print(LIST L)
{
	// cout << "Thong tin mat hang: \n";
	// cout << left << setw(15) << "Ma sp" << setw(15) << "Ten sp" << setw(15) << "SL nhap" << setw(15) << "SL xuat" << setw(15) << "Don gia nhap" << setw(15) << "Don gia xuat" << setw(15) << "SL ton" << setw(15) << "So tien ton";
	// cout << endl;

	// LIST x = L;
	// while (x != NULL)
	// {
	// 	string temp;
	// 	cpydata_string(temp, x->Name);
	// 	cout << left << setw(15) << x->ID << setw(15) << temp << setw(15) << x->Num_In << setw(15) << x->Num_Out << setw(15) << x->Price_In << setw(15) << x->Price_Out << setw(15) << x->Num_In - x->Num_Out << setw(15) << x->Num_Out * x->Price_Out - x->Num_In * x->Price_In;
	// 	cout << endl;
	// 	x = x->next;
	// }
}
void Y2(LIST &L)
{
}
void Y3(LIST &L)
{
}
void Y4(LIST &L)
{
}
// Bao
void Y5(LIST &L)
{
}
void Y6(LIST &L)
{
}
void Y7(LIST &L)
{
}
void Y8(LIST &L)
{
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