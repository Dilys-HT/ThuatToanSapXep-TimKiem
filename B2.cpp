#include<iostream>
#include<ctime>
using namespace std;

// XEP THU TU VA TIM KIEM

// Khoi tao ds ngau nhien
void random(int a[], int& n)
{
	cout << "Nhap so luong phan tu trong danh sach: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Loi! Vui long nhap lai: n=";
		cin >> n;
	}
	srand((int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
}

// Nhap ds
void input(int a[], int& n)
{
	cout << "Nhap so luong phan tu trong danh sach: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Loi! Vui long nhap lai: n=";
		cin >> n;
	}
	cout << "Nhap cac phan tu trong danh sach:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}

// Xuat ds
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << a[i];
	}
	cout << endl;
}

// SELECTION SORT
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vtmin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[vtmin] > a[j])
			{
				vtmin = j;
			}
		}
		swap(a[i], a[vtmin]);
	}
}

// INSERTION SORT
void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i]; // Ptu muon chen vao ds
		int pos = i - 1;
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

// BUBBLE SORT
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
			}
		}
	}
}

// INTERCHANGE SORT
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

// QUICK SORT
void QuickSort(int a[], int left, int right)
{
	int mid = a[(left + right) / 2];
	int l = left, r = right;
	while (l <= r)
	{
		while (a[l] < mid)
			l++;
		while (a[r] > mid)
			r--;

		if (l <= r)
		{
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	if (left < r)
		QuickSort(a, left, r);
	if (l < right)
		QuickSort(a, l, right);
}

// HEAP SORT
void shift(int a[], int i, int n)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left <n && a[left] > a[largest])
		largest = left;
	if (right < n && a[right] > a[largest])
		largest = right;
	if (largest != i)
	{
		int x = a[i];
		a[i] = a[largest];
		a[largest] = x;
		shift(a, largest, n);
	}
}

void HeapSort(int a[], int n)
{
	for (int i = n / 2; i >= 0; i--)
	{
		shift(a, i, n - 1);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		shift(a, 0, i);
	}
}

// MERGE SORT
int* merge(int* a, int n1, int* b, int n2)
{
	int* c = new int(n1 + n2);
	int i = 0, j = 0, dem = 0;
	while (i < n1 && j < n2)
	{
		if (a[i] < b[j])
		{
			c[dem++] = a[i++];
		}
		else
		{
			c[dem++] = b[j++];
		}
	}

	for (int k = i; k < n1; k++)
	{
		c[dem++] = a[k];
	}
	for (int k = j; k < n2; k++)
	{
		c[dem++] = b[k];
	}

	return c;
}

int* MergeSort(int a[], int n)
{
	if (n == 1)
		return a;
	int mid = n / 2;
	int* m1 = new int[mid];
	int* m2 = new int[n - mid];

	for (int i = 0; i < mid; i++)
		m1[i] = a[i];
	for (int i = 0; i < n - mid; i++)
		m2[i] = a[mid + i];

	m1 = MergeSort(m1, mid);
	m2 = MergeSort(m2, n - mid);

	return merge(m1, mid, m2, n - mid);
}

// TIM KIEM TUAN TU
int Search_tt(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if (i < n)
		return i;
	return -1;
}

// TIM KIEM NHI PHAN
// ?anh sach phai duoc sap xep theo thu tu
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1; // Ko tim thay x
}

int main() {
	int a[] = { 0 };
	int n = 0, x = 0;
	int op = 0;
	bool check = true;

	cout << " ------- CHUONG 3 : XEP THU TU VA TIM KIEM -------\n";
	cout << "0. Khoi tao danh sach ngau nhien\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Xep thu tu danh sach bang SELECTION SORT\n";
	cout << "4. Xep thu tu danh sach INSERTION SORT\n";
	cout << "5. Xep thu tu danh sach bang BUBBLE SORT\n";
	cout << "6. Xep thu tu danh sach bang INTERCHANGE SORT\n";
	cout << "7. Xep thu tu danh sach QUICK SORT\n";
	cout << "8. Xep thu tu danh sach bang HEAP SORT\n";
	cout << "9. Xep thu tu danh sach bang MERGE SORT\n";
	cout << "10. Tim kiem phan tu x bang TIM KIEM TUAN TU\n";
	cout << "11. Tim kiem phan tu xbang TIM KIEM NHI PHAN\n";
	cout << "12. Thoat\n";
	while (check == true)
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{
			random(a, n);
			break;
		}
		case 1:
		{
			input(a, n);
			break;
		}
		case 2:
		{
			cout << "Cac phan tu trong danh sach:\n";
			output(a, n);
			break;
		}
		case 3:
		{
			cout << "Xep thu tu danh sach bang SELECTION SORT:\n";
			SelectionSort(a, n);
			output(a, n);
			break;
		}
		case 4:
		{
			cout << "Xep thu tu danh sach bang INSERTION SORT:\n";
			InsertionSort(a, n);
			output(a, n);
			break;
		}
		case 5:
		{
			cout << "Xep thu tu danh sach bang BUBLLE SORT:\n";
			BubbleSort(a, n);
			output(a, n);
			break;
		}
		case 6:
		{
			cout << "Xep thu tu danh sach bang INTERCHANGE SORT:\n";
			InterchangeSort(a, n);
			output(a, n);
			break;
		}
		case 7:
		{
			cout << "Xep thu tu danh sach bang QUICK SORT:\n";
			QuickSort(a, 0, n - 1);
			output(a, n);
			break;
		}
		case 8:
		{
			cout << "Xep thu tu danh sach bang HEAP SORT:\n";
			HeapSort(a, n);
			output(a, n);
			break;
		}
		case 9:
		{
			cout << "Xep thu tu danh sach bang MERGE SORT:\n";
			int* b = MergeSort(a, n);
			output(b, n);
			delete[] b;
			break;
		}
		case 10:
		{
			cout << "TIM KIEM TUAN TU:\n";
			cout << "Nhap so can tim: ";
			cin >> x;
			if (Search_tt(a, n, x) != -1)
			{
				cout << "Phan tu " << x << " o vi tri " << Search_tt(a, n, x) << "!\n";
			}
			else
			{
				cout << "Khong tim thay " << x << " trong danh sach!\n";
			}
			break;
		}
		case 11:
		{
			cout << "TIM KIEM NHI PHAN:\n";
			cout << "Nhap so can tim: ";
			cin >> x;
			if (BinarySearch(a, n, x) != -1)
			{
				cout << "Phan tu " << x << " o vi tri " << BinarySearch(a, n, x) << "!\n";
			}
			else
			{
				cout << "Khong tim thay " << x << " trong danh sach!\n";
			}
			break;
		}
		case 12:
		{
			check = false;
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