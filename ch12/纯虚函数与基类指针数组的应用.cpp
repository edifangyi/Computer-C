/*********************************************************************
题目内容：
定义抽象基类Shape, 
其中纯虚函数printName（）输出几何图形的名称和相应的成员数据、纯虚函数printArea（）计算几何图形的面积。
并由Shape类派生出5个派生类：Circle（圆形），数据成员为半径、Square(正方形) 
，数据成员为边长、Rectangle(长方形) ，数据成员为长和宽、
Trapezoid(梯形) ，数据成员为上底、下底和高、Triangle(三角形) 
，数据成员为底和高。测试过程，定义一个指向基类的指针数组，使其每个元素指向一个动态产生的派生类对象，
分别调用相应的成员函数显示各个几何图形的属性及面积，最终输出总面积值。

输入格式:
依次输入圆半径、正方形边长、长方形长宽、梯形上底下底和高、三角形底边和高

输出格式：
请参考输出样例，建议直接复制样例中的部分文字粘贴进自己的代码。圆周率取 3.14159

输入样例：
10
5
2 4
1 2 3
4 3

输出样例：
圆:半径=10,面积:314.159
正方形:边长=5,面积:25
长方形:长=2,宽=4,面积:8
梯形:上底=1,下底=2,高=3,面积:4.5
三角形:底边=4,高=3,面积:6
总面积:357.659

********************************************************************************************/
*#include<iostream>
#include<cstdlib>
using namespace std;
class Shape
{
public:
	virtual void printName() = 0;
	virtual double printArea() = 0;
};

class Circle:public Shape
{
	double R;
public:
	Circle(double r){ R = (r >= 0 ? r : 0); }
	double printArea() { return 3.14159*R*R; }//计算面积
	void printName() { cout << "圆:半径=" << R << ",面积:" << printArea() << endl; }//输出数据
};

class Square:public Shape
{
	double A;
public:
	Square(double a) { A = (a >= 0 ? a : 0); }
	double printArea() { return A*A; }//计算面积
	void printName(){ cout << "正方形:边长=" << A << ",面积:" << printArea() << endl; }//输出数据
};

class Rectangle:public Shape
{
	double A, B;
public:
	Rectangle(double a, double b) {
		A = (a >= 0 ? a : 0);
		B = (b >= 0 ? b : 0);
	}
	double printArea() { return A*B; }//计算面积
	void printName() { cout << "长方形:长=" << A << ",宽=" << B << ",面积:" << printArea() << endl; }//输出数据
};

class Trapezoid:public Shape
{
	double A, B, H;
public:
	Trapezoid(double a, double b, double h)
	{
		A = (a >= 0 ? a : 0);
		B = (b >= 0 ? b : 0);
		H = (h >= 0 ? h : 0);
	}
	double printArea() { return ((A + B)*H / 2); }//计算面积
	void printName() { cout << "梯形:上底=" << A << ",下底=" << B << ",高=" << H << ",面积:" << printArea() << endl; }//输出数据
};


class Triangle :public Shape
{
	double A, H;
public:
	Triangle(double a, double h)
	{
		A = (a >= 0 ? a : 0);
		H = (h >= 0 ? h : 0);
	}
	double printArea() { return (A*H / 2); }//计算面积
	void printName() { cout << "三角形:底边=" << A << ",高=" << H << ",面积:" << printArea() << endl; }//输出数据
};

int main()
{
	double a1, a2, a3, a4, r, b1, b2, h1, h2;
	cin >> r;
	cin >> a1;
	cin >> a2 >> b1;
	cin >> a3 >> b2 >> h1;
	cin >> a4 >> h2;

// 	Shape *p1, *p2, *p3, *p4, *p5;
// 	Shape *p6, *p7, *p8, *p9, *p0;

	Circle cir(r);
	Square squ(a1);
	Rectangle ret(a2, b1);
	Trapezoid tra(a3, b2, h1);
	Triangle tri(a4, h2);

// 	p6 = &cir;
// 	p6->printName();
// 	cout << p6->printArea() << endl;
// 	p7 = &squ;
// 	p7->printName();
// 	cout << p7->printArea() << endl;
// 	p8 = &ret;
// 	p8->printName();
// 	cout << p8->printArea() << endl;
// 	p9 = &tra;
// 	p9->printName();
// 	cout << p9->printArea() << endl;
// 	p0 = &tri;
// 	p0->printName();
// 	cout << p0->printArea() << endl;
// 
// 	cout << "*******************************" << endl;
// 
// 	p1 = new Circle(r);
// 	p1->printName();
// 	cout << p1->printArea() << endl;
// 
// 	p2=new Square(a1);
// 	p2->printName();
// 	cout << p2->printArea() << endl;
// 
// 	p3=new Rectangle(a2, b1);
// 	p3->printName();
// 	cout << p3->printArea() << endl;
// 
// 	p4=new Trapezoid(a3, b2, h1);
// 	p4->printName();
// 	cout << p4->printArea() << endl;
// 
// 	p5=new Triangle(a4, h2);
// 	p5->printName();
// 	cout << p5->printArea() << endl;
// 
// 	cout << "*******************************" << endl;

	double sum = 0;
	Shape *p[5] = { &cir,&squ,&ret,&tra,&tri };
	for (int i = 0;i < 5;i++) {
		p[i]->printName();
		sum += p[i]->printArea();
	}
	cout << "总面积:" << sum;
/*	delete p1, p2, p3, p4, p5;*/
	system("pause");
	return 0;
}