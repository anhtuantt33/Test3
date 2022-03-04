#include <iostream>
using namespace std;
template <class T> 
class Alist{
  int * list;
  int maxSize;
  int size;
  public:
  Alist (T n){
    if(n<0) throw "kich thuoc mang khong the am ";
    maxSize = n;
    list = new int [50];
    size = 0;
  } 
  ~Alist(){delete [] list;} 
bool isEmpty(){return size == 0;}
bool isFull(){return size == maxSize;} 
void add(T i, T t){
    if(isFull()) throw "danh sach day khong the chen them";
    	if (i < 0 || i > size) throw "Chi so khong hop le";
		for (int j = size; j > i; j--) list[j] = list[j - 1];
		list[i] = t;
		size++;
  }; 
void remove(T i) 
	{
		if (isEmpty()==true) throw "Danh sach rong, khong the xoa";
		if (i<0 || i>size - 1) throw "Chi so sai";
		for (int j = i; j < size - 1; j++) list[j] = list[j + 1];
		size--;
	}; 
void print(){
		for (int i = 0; i < size; i++){
			cout << list[i] << " ";
		}
	}; 
void clear(){
  size = 0; 
  }; 
void replace(T i, T x)
  {
    list[i]=x;
  } 
void removeKey(T x){
  for (int j = 0; j < size; j++)
  {
  if (list[j]==x) list[j] = list[j + 1];
  }
	size--; 
  }
int search(T x) {
	for (int i = 0; i < size; i++)
	{
    if (list[i] == x)
			return i;
	}
	return -1;
	} 
 
};

int main() {
  Alist<int> l(10);
  cout<<l.isEmpty();
  cout<<l.isFull();
  l.add(0,6);
  l.remove(4);
  l.print();
  l.clear();
  l.replace(1,4);
  l.removeKey(4);
  cout<<l.search(5)<<endl;
}
