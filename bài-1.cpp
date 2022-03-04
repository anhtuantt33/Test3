#include <iostream>
using namespace std;
template <class T>
class AList
{
	int  maxSize;
	int size;
	T* list;
public:
	AList(int a) //hàm tạo
	{
		if (a < 0) throw "Kich thuoc mang khong the am!";
		maxSize = a;
		list = new T[a];
		size = 0;
	}
	AList(AList &n)
	{
		if (n.list < 0) throw "Kich thuoc mang khong the am!";
		maxSize = n.maxSize;
		n.list = new T[];
		n.size = 0;
	}
	void print() //in ra danh sách mảng
	{
		for (int i = 0; i < size; i++)
		{
			cout << list[i] << endl;
		}
	}
	~AList() //hàm hủy
	{
		delete[]list;
	}
	bool isEmpty() //ktra rỗng
	{
		return size == 0;
	}
	bool isFull() //ktra đầy
	{
		return size == maxSize;
	}
	int search(T v) //tìm chỉ số phần tử
	{
		for (int i = 0; i < size; i++)
		{
			if (list[i] == v)
				return i;
		}
		return -1;
	}
	int getSize() //ktra kích thước mảng
	{
		return size;
	}
	void clear() { size = 0; } //xóa về rỗng
	void remove(int a) //xóa phần tử ở vị trí đã cho
	{
		if (isEmpty()) throw "Danh sach rong, khong the xoa";
		if (a<0 || a>size - 1) throw "Chi so sai";
		for (int b = a; b < size - 1; b++) list[b] = list[b + 1];
		size--;
	}
	void add(int a, T e) // thêm phần tử
	{
		if (isFull()) throw "Danh sach day, khong the chen them";
		if (a < 0 || a > size) throw "Chi so khong hop le";
		for (int j = size; j > a; j--) list[j] = list[j - 1];
		list[a] = e;
		size++;
	}
	bool find(T a) // tìm kiếm
	{
		for (int i = 0; i < maxSize; i++)
		{
			if (list[i] == a)
			{
				return true;
			}
		}
	}
	void addKey(T a)
	{
		if (find(a) == true) throw "Khong them duoc, da co trong danh sach";
		else
		{
			list[size + 1] = a;
		}
	}
	void removeKey(T a) //xóa phần tử có gtri cho trước
	{
		if (isEmpty())throw "Danh sach rong, khong the xoa";
		if (find(a) == false) throw "Khong the xoa, khong ton tai";
		for (int i = 0; i < size; i++)
		{
			if (list[i] == a)
			{
				list[i] == list[i + 1];
			}
		}
		size--;
	}
	void replace(T i, T a) //thay thế
	{
		list[i] = a;
	}
	bool isEqual(T a, T b)
	{
		if (list[a] == list [b])
		{
			return true;
		}
	}
	void Swap(T a, T b) //đổi chỗ
	{
		int tmp = list[a];
		list[a] = list[b];
		list[b] = tmp;
	}
	int countKey(T a)
	{
		int count;
		for (int i = 0; i < size; i++)
		{
			if (list[i] == a) throw "Bat dau dem so lan xuat hien";
			count++;
		}
		return count;
	}
	void operator = (const AList& y)
	{
		if (y.list < 0) throw"Kich thuoc mang khong the am!";
		maxSize = y.maxSize;
		list = new int[];
		size = 0;
	}
};
int main()
{
	AList<int> x(6);
	AList<int> y(x);
	cout << x.isEmpty() << endl;
	x.add(0, 7);
	x.add(0, 8);
	cout << x.getElement(0) << endl;
	cout << x.getElement(1) << endl;
	x.print();
	cout << x.search(7) << endl;
	x.remove(7);
	x.print();
	cout << x.getSize() << endl;
	cout << x.isEmpty() << endl;
	cout << x.find(7);
	x.addKey(9);
	x.clear();
	x.removeKey(8);
	x.replace(1, 10);
	x.isEqual(0, 1);
	x.Swap(0, 1);
	x.countKey(8);
}
