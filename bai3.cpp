#include <iostream>
using namespace sst;
gdghssfj
ghshjfdhdzfjk
class A{
  int  maxSize;
	int size;
	T* list;
public:
  A(int a){
    if (a < 0) throw "Kich thuoc mang khong the am!";
		maxSize = a;
		list = new T[a];
		size = 0;
  };

bool isFull()
	{
		return size == maxSize;
	};

  bool isEmpty() //ktra rỗng
	{
		return size == 0;
	};

  void add(T e){
    if (isFull()) throw "Danh sach day, khong the chen them";
		list[size] = e;
		size++;
  };

  void Swap(T a, T b) 
	{
		int tmp = list[a];
		list[a] = list[b];
		list[b] = tmp;
	};

  void BubbleSort(int a[], int n){	
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
		   if(a[j] < a[j-1])
		       Swap(a[j], a[j-1]);
};

void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << list[i] << endl;
		}
	};


};

int main() {
  int a;
  A list;
  
}
