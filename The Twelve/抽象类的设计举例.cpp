/************************************************************
平面上的几何图形可以抽象定义为类，如矩阵类、圆类、三角类等
将所有的几何图形再加以抽象，定义为形状类
将形状类定义为抽象类shape
由于几何图形类中都包含求面积函数和求周长函数
在shape类中，将函数area()和circumenference()声明为纯虚数函数
再用shape类派生出矩形类和圆类，在派生类中具体定义相应的求面积与周长函数
通过抽象类的对象指针访问派生类对象，实现动态绑定
*************************************************************/


#include "iostream"
#include "cstring"
using namespace std;
#define PI 3.1415926

class Shape
{
public:
	virtual double area() = 0;
	virtual double circumference() = 0;
};

class Rectangle :public Shape	//矩形类
{
	int x, y;
	int width, hight;
public:
	Rectangle(int x,int y,int w,int h)
	{
		this->x = x;this->y = y;	width = w;hight = h;
	}
	virtual double area()
	{
		return width *hight;
	}
	virtual double circumference()
	{
		return 2.0*(width + hight);
	}
};

class Circle:public Shape	//圆类
{
	int x, y;
	int r;
public:
	Circle(int x, int y, int r)
	{
		this->x = x;this->y = y;this->r = r;
	}
	virtual double area()
	{
		return PI*r*r;
	}
	virtual double circumference()
	{
		return 2.0*PI*r;
	}
};



int main()
{
	Rectangle r1(10, 10, 10, 5);
	Circle c1(1, 2, 1);
	Shape *p1 = &r1, &p2 = c1;
	cout << "长方形面积：" << p1->area() << endl;
	cout << "长方形周长" << p1->circumference() << endl;
	cout << "圆面积" << p2.area() << endl;
	cout << "圆周长" << p2.circumference() << endl;
	system("pause");
	return 0;
}