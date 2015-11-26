/*****************************************************************************************************************************
题目内容：
已知基类Point的定义如下： 

class Point
{ 
int x, y; //点的x和y坐标 
public: Point( int = 0, int = 0 ); // 构造函数 
void SetPoint( int, int ); // 设置坐标 
int GetX() { return x; } // 取x坐标 
int GetY() { return y; } // 取y坐标 
void Print(); //输出点的坐标 }; 
Point( int a, int b ) { SetPoint( a, b ); } 
void SetPoint( int a, int b ) { x = a; y = b; } 
void Print() { cout << "[" << x << ", " << y << "]"; 
} 

请通过继承的方法建立一个派生类Circle，其中 
1．新增的数据成员有： double radius; 
2.新增的成员函数有： 
Circle(int x = 0, int y = 0 , double r = 0.0); //对数据成员赋值，并使用SetRadius和基类的Point 
void SetRadius( double ); //设置半径 
double GetRadius(); //取半径 
double Area(); //计算面积 
void Print(); //输出圆心坐标和半径，并使用基类的Print 
在主程序中分别建立基类对象和派生类对象，使用用户输入的初值分别对基类对象和派生类对象的数据成员赋值后，利用已有的成员函数分别显示基类对象和派生类对象的数据成员信息。
圆周率取3.14。 

输入格式:
第一行是Point类的初始化信息，第二行是Circle类的初始化信息

输出格式：
请参考输出样例，严格按照样例输出，建议直接将部分文字复制粘贴进程序代码中

输入样例：
30 50 
120 80 10 

输出样例：
Point p [30,50]
Circle c Center=[120,80]
Radius=10
The centre of circle c [120,80]
The area of circle c 314
*****************************************************************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;

class Point
{
	int x, y; //点的x和y坐标 
public: 
		int GetX() { return x; } // 取x坐标 
		int GetY() { return y; } // 取y坐标 
		Point(int a, int b) { SetPoint(a, b); }
		void SetPoint(int a, int b) { x = a; y = b; }
		void Print() {
			cout << "[" << x << "," << y << "]";
		}
};
class Circle:public Point
{
	double radius;
public:
	Circle(int x = 0, int y = 0, double r = 0.0);
	void SetRadius(double);//设置半径
	double GetRadius();//取半径
	double Area();//计算面积
	void Print();//输出圆心坐标和半径
};
Circle::Circle(int a, int b, double r) :Point(a, b) { SetRadius(r); }
void Circle::SetRadius(double r) { radius = (r >= 0 ? r : 0); }
double Circle::GetRadius() { return radius; }
double Circle::Area() { return 3.14*radius*radius; }
void Circle::Print()
{
	cout << "Center=";
	Point::Print();
	cout << endl << "Radius=" << radius;
}

int main()
{
// 	Point p(30, 50);
// 	Circle c(120, 80, 10.0);
	int x1, y1;
	int x2, y2;
	double r;
	cin >> x1 >> y1 >> x2 >> y2 >> r;
	Point p(x1, y1);
	Circle c(x2, y2, r);
	cout << "Point p ";
	p.Print();
	cout << endl;
	cout << "Circle c ";
	c.Print();
	cout << endl;
	cout << "The centre of circle c ";
	c.Point::Print();
	cout << endl;
	cout << "The area of circle c " << c.Area() << endl;
	return 0;
}
