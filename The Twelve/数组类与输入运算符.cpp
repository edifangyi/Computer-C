/************************************************************
设计一个数组类，其成员变量包括数组标签、数组元素个数和数组变量
定义成员函数：构造、析构以及数组显示函数、排序和两个数组的加法函数
在主函数中定义数组类的对象，并调用函数显示数组，对一个数组进行排序
以及计算两个数组的加
*************************************************************/


#include "iostream"
#include "cstring"
#include "string"
using namespace std;

class Array
{
private:
	string name;//数组名称
	int count;	//数组大小
	int *data;	//数组变量
public:
	Array();//默认构造函数
	Array(string name, const int *data, int count);//构造函数
	~Array();//析构函数
	void print();//显示数组元素函数
	friend ostream & operator<<(ostream & out, const Array & array);
	void order();//数组排序函数
	Array add(const Array&array);//数组加法函数
	Array operator+(const Array & array);
};

Array::Array() {
	name = "";
	count = 0;
	data = NULL;
}
Array::Array(string name, const int *data, int count)
{
	this->name = name;
	this->count = count;
	this->data = new int[this->count];
	for (int i = 0;i < this->count;i++)
	{
		this->data[i] = data[i];
	}
}
Array::~Array()
{
	if (data!=NULL)
	{
		delete[]data;
		count = 0;
	}
}

void Array::print()
{
	cout << name << ": ";
	for (int i = 0;i < count;i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

ostream & operator<<(ostream & out, const Array & array)
{
	out << array.name << " .";
	for (int i = 0;i < array.count;i++)
	{
		out << array.data[i] << " ";
	}
	out << endl;
	return out;
}


void Array::order()
{
	for (int i = 0;i < count - 1;i++)
	{
		for (int j = 0;j < count - i - 1;j++)
		{
			if (data[j]>data[j+1])
			{
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

Array Array::add(const Array & array)
{
	Array temp;
	int max = (count > array.count ? count : array.count);
	int min = (count < array.count ? count : array.count);
	temp.name = this->name + " + " + array.name;
	temp.count = max;
	temp.data = new int[temp.count];
	int i = 0;
	for (i = 0;i < min;i++)
	{
		temp.data[i] = data[i] + array.data[i];
	}
	for (;i < count;i++)
	{
		temp.data[i] = data[i];
	}
	for (;i < array.count;i++)
	{
		temp.data[i] =array.data[i];
	}
	return temp;
}

Array Array::operator+(const Array & array)
{
	Array temp;
	int max = (count > array.count ? count : array.count);
	int min = (count < array.count ? count : array.count);
	temp.name = this->name + " + " + array.name;
	temp.count = max;
	temp.data = new int[temp.count];
	int i = 0;
	for (i = 0;i < min;i++)
	{
		temp.data[i] = data[i] + array.data[i];
	}
	for (;i < count;i++)
	{
		temp.data[i] = data[i];
	}
	for (;i < array.count;i++)
	{
		temp.data[i] = array.data[i];
	}
	return temp;
}



int main()
{
	int data1[] = { 9,8,7,6,5,4,3,2,1,0 };
	Array array1("array1", data1, 10);
	array1.print();
	cout << array1;

	int data2[] = { 1,3,5,7,8,6,4,2 };
	Array array2("array2", data2, 8);
	array2.print();
	cout << array2;

	(array1.add(array2)).print();
	cout << (array1 + array2);

	array1.order();
	cout << "排序后， ";
	array1.print();
	cout << "排序后， " << array1;

	array2.order();
	cout << "排序后， ";
	array2.print();

	cout << "排序后， " << array2;
	system("pause");
	return 0;
}