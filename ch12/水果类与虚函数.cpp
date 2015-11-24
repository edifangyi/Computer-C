/************************************************************
设计一个水果类Fruit作为基类，成员函数为显示“水果”函数；
设计Fruit类的四个派生类：香蕉类Banana/苹果类Apple/梨子类Pear/桃子类Peach，
成员函数分别为显示“香蕉”“苹果”“梨子”“桃子”函数；
在主函数中定义这些类的对象，并调用他们的显示函数。

虚函数是多态的一种实现形式；
作用是实现函数的覆盖；
写法是将virtual加载函数之前；
在类的继承当中的基类尽量多使用虚函数。
*************************************************************/


#include "iostream"
#include "cstring"
using namespace std;
class Fruit
{
public:
	virtual void print()
	{
		cout << "水果" << endl;
	}
};

class Banana :public Fruit
{
public:
	void print()
	{
		cout << "香蕉" << endl;
	}
};

class Apple :public Fruit
{
public:
	void print()
	{
		cout << "苹果" << endl;
	}
};

class Pear :public Fruit
{
public:
	void print()
	{
		cout << "梨子" << endl;
	}
};

class Peach :public Fruit
{
public:
	void print()
	{
		cout << "桃子" << endl;
	}
};

int main()
{
	
	Fruit *pFruit[] = {
	new Fruit(),
	new Banana(),
	new Apple(),
	new Pear(),
	new Peach()
	};

	for (int i = 0;i < 5;i++)
	{
		(*pFruit[i]).print();
	}

	system("pause");
	return 0;
}