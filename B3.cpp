#include<iostream>
using namespace std;

// QUAN LY 1 DS DUNG DS LIEN KET DOI = LIEN KET KEP

// Khai bao cau truc ds
struct Node
{
	int info;
	Node* next, * prev;
};

Node* first, * last;

// Khoi tao ds rong
void init()
{
	first = NULL;
	last = NULL;
}

// Xuat cac ptu trong ds
// Tu DAU => CUOI
void output_f()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << "\t" << p->info;
		p = p->next;
	}
	cout << endl;
}
// Tu CUOI => DAU
void output_l()
{
	Node* p = last;
	while (p != NULL)
	{
		cout << "\t" << p->info;
		p = p->prev;
	}
	cout << endl;
}

// Them 1 ptu vao dau ds
void Insert_f(int x)
{
	Node* p = new Node;
	p->info = x;
	p->next = first;
	p->prev = NULL;
	if (first != NULL)
	{
		first->prev = p;
	}
	else
	{
		last = p;
	}
	first = p;
}

// Them 1 ptu vao cuoi ds
void Insert_l(int x)
{
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	p->prev = last;
	if (last != NULL)
	{
		last->next = p;
	}
	else
	{
		first = p;
	}
	last = p;
}

// Xoa ptu dau ds
int Delete_f()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->next;
		delete p;
		if (first != NULL)
		{
			first->prev = NULL;
		}
		else
		{
			last = NULL;
		}
		return 1;
	}
	return 0;
}

// Xoa ptu cuoi ds
int Delete_l()
{
	if (first != NULL)
	{
		Node* p = last;
		last = last->prev;
		delete p;
		if (first != NULL)
		{
			last->next = NULL;
		}
		else
		{
			first = NULL;
		}
		return 1;
	}
	return 0;
}

// Tim ptu trog ds, neu co xao ptu do
int Delete_x(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p = p->next;
	}
	if (p != NULL)
	{
		if (p->prev != NULL)
		{
			p->prev->next = p->next;
		}
		else
		{
			first = p->next;
		}
		if (p->next != NULL)
		{
			p->next->prev = p->prev;
		}
		delete p;
		return 1;
	}
	return 0;
}

// Tim ptu co gia tri gan bang gia tri x

// Them 1 ptu vao trc ptu ngau nhien
int Insert_x(int ptu, int x)
{
	if (first != NULL)
	{
		Node* p = first;
		while (p != NULL && p->info != ptu)
		{
			p = p->next;
		}
		if (p != NULL)
		{
			Node* q = new Node;
			q->info = x;
			q->next = NULL;
			q->prev = NULL;
			if (p->prev != NULL)
			{
				p->prev->next = q;
				p->prev = q;
				q->next = p;
			}
			else
			{
				p->prev = q;
				q->next = p;
				first = q;
			}
			return 1;
		}
	}
	return 0;
}

int main() {
	int op = 0;
	bool check = true;

	int x = 0;

	init();

	cout << " ======= MENU =======\n\n";
	cout << "0. Xuat cac phan tu trong danh sach tu dau => cuoi\n";
	cout << "1. Xuat cac phan tu trong danh sach tu cuoi => dau\n";
	cout << "2. Them 1 ptu vao dau danh sach\n";
	cout << "3. Them phan tu vao cuoi danh sach\n";
	cout << "4. Xoa phan tu dau danh sach\n";
	cout << "5. Xoa phan tu cuoi danh sach\n";
	cout << "6. Xoa phan tu ngau nhien trong danh sach\n";
	cout << "7. Tim phan tu co gia tri gan bang x\n";
	cout << "8. Them phan tu truoc phan tu ngau nhien\n";
	cout << "\nNhan 1 phim bat ky de thoat chuong trinh\n";

	while (check)
	{
		cout << "\n==>Lua chon cua ban: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{
			cout << "Cac phan tu trong danh sach (Dau=>Cuoi):\n";
			output_f();
			break;
		}
		case 1:
		{
			cout << "Cac phan tu trong danh sach (Cuoi=>Dau):\n";
			output_l();
			break;
		}
		case 2:
		{
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Insert_f(x);
			break;
		}
		case 3:
		{
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Insert_l(x);
			break;
		}
		case 4:
		{
			if (Delete_f() != 0)
			{
				cout << "Da xoa thanh cong!\n";
			}
			else
			{
				cout << "Xoa khong thanh cong!\n";
			}
			break;
		}
		case 5:
		{
			if (Delete_l() != 0)
			{
				cout << "Da xoa thanh cong!\n";
			}
			else
			{
				cout << "Xoa khong thanh cong!\n";
			}
			break;
		}
		case 6:
		{
			cout << "Nhap phan tu can xoa: ";
			cin >> x;
			if (Delete_x(x) != 0)
			{
				cout << "Da xoa thanh cong!\n";
			}
			else
			{
				cout << "Xoa khong thanh cong!\n";
			}
			break;
		}
		case 8:
		{
			int ptu = 0;
			cout << "Nhap phan tu can tim: "; cin >> ptu;
			cout << "Nhap phan tu can them vao truoc " << ptu << ": "; cin >> x;
			if (Insert_x(ptu, x) != 0)
			{
				cout << "Da them thanh cong!\n";
			}
			else
			{
				cout << "Them khong thanh cong!\n";
			}
			break;
		}
		default:
		{
			check = false;
			break;
		}
		}
	}

	system("pause");
	return 0;
}