/*****************************************************************************************************************************
题目内容：
设计并测试一个名为Trapezium的梯形类，其属性为梯形的四个顶点的坐标。该梯形上边和下边均和x轴平行。
根据类的封装性要求，在类的声明中用8个私有的整型变量表示4个点的坐标值，声明成员函数initial(int,int,int,int,int,int,int,int)
初始化数据成员，函数GetPosition(int&,int&,int&,int&,int&,int&,int&,int&)读取坐标值，函数Area()计算面积。

输入格式:
梯形四个顶点的坐标，

输出格式：
梯形的面积，依次为左上(x1,y1)、右上(x2,y2)、左下(x3,y3)和右下(x4,y4)角的顶点。

输入样例：
3 2 5 2 1 -4 7 -4

输出样例：
24
*****************************************************************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;
class Trapezium
{
private:
	int x1, y1, x2, y2, x3, y3, x4, y4;
public:
	Trapezium(int, int, int, int, int, int, int, int);
	void GetPosition(int&, int&, int&, int&, int&, int&, int&, int&);
	double Area();
};
Trapezium::Trapezium(int a, int b, int c, int d,int e,int f,int g,int h) :x1(a), y1(b), x2(c), y2(d), x3(e), y3(f), x4(g), y4(h)
{}
void Trapezium::GetPosition(int &a, int &b, int &c, int &d, int &e, int &f, int &g, int &h)
{
	a = x1, b = y1, c = x2, d = y2, e = x3, f = y3, g = x4, h = y4;
}
double Trapezium::Area()
{
	return (double)abs((x2 - x1) + (x4 - x3))*(y1 - y3) / 2;
}
int main()
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	Trapezium e1(x1, y1, x2, y2, x3, y3, x4, y4);
	e1.GetPosition(x1, y1, x2, y2, x3, y3, x4, y4);
	cout << e1.Area() << endl;
	return 0;
}
