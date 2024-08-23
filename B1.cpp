// THUAT TOAN SAP XEP
#include <iostream>
using namespace std;

// Nhap danh sach
void input(int a[], int& n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	cout << endl;
}

// Xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << a[i];
	}
	cout << endl;
}

// INSERTION SORT
void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i]; // Ptu muon chen vao
		int pos = i - 1;
		// Di chuyen cac ptu lon hon x lui ve sau 1 vtri
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

// SELECTION SORT
void SelectionSort(int a[], int n)
{
	// Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	for (int i = 0; i < n - 1; i++)
	{
		int vtmin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[vtmin])
			{
				vtmin = i;
			}
		}
		// Hoan doi ptu nho nhat voi ptu dau tien
		swap(a[vtmin], a[i]);
	}
}

// BUBBLE SORT
void BubbleSort(int a[], int n)
{
	// Sap xep theo hoan doi ptu dau & cuoi
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j - 1] > a[j]) // Xet ptu sau nho hon ptu trc
			{
				swap(a[j - 1], a[j]);
			}
		}
	}
}

// INTERCHANGE
void Interchange(int a[], int n)
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
	do {
		while (a[l] < mid)
		{
			l++;
		}
		while (a[r] > mid)
		{
			r--;
		}

		if (l <= r)
		{
			swap(a[l], a[r]);
			l++;
			r--;
		}
	} while (l <= r);
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

int main() {
	int a[] = { 0 };
	int n = 0;

	cout << "\t\t THUAT TOAN SAP XEP\n\n";
	input(a, n);

	cout << "Cac phan tu trong danh sach:\n";
	output(a, n);

	cout << "Xep thu tu danh sach bang INSERTION SORT:\n";
	InsertionSort(a, n);
	output(a, n);

	cout << "Xep thu tu danh sach bang SELECTION SORT:\n";
	SelectionSort(a, n);
	output(a, n);

	cout << "Xep thu tu danh sach bang BUBBLE SORT:\n";
	BubbleSort(a, n);
	output(a, n);

	cout << "Xep thu tu danh sach bang INTERCHANGE:\n";
	Interchange(a, n);
	output(a, n);

	cout << "Xep thu tu danh sach bang QUICK SORT:\n";
	QuickSort(a, 0, n - 1);
	output(a, n);

	cout << "Xep thu tu danh sach bang HEAP SORT:\n";
	HeapSort(a, n);
	output(a, n);

	cout << "Xep thu tu danh sach bang MERGE SORT:\n";
	//int x[] = { 0 }, y[] = { 0 };
	//int n1 = 0, n2 = 0;
	//cout << "Nhap day con thu 1:\n";
	//input(x, n1);
	//cout << "Nhap day con thu 2:\n";
	//input(y, n2);
	//cout << "2 day con sau khi nhap:\n";
	//output(x, n1);
	//output(y, n2);
	//int* z = merge(x, n1, y, n2);
	//cout << "Day danh sach sau khi tron:\n";
	//output(z, n1 + n2);
	int* b = MergeSort(a, n);
	output(b, n);

	delete[]b;
	system("pause");
	return 0;
}