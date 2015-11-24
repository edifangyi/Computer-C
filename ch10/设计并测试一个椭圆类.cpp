/*****************************************************************************************************************************
题目内容：
设计并测试一个名为Ellipse的椭圆类，其属性为圆心坐标及长半轴和短半轴的长度。设计一个构造函数（Ellipse(int,int,double,double)）对这些属性进行初始化，并通过成员函数计算出椭圆的面积（double 
Area()）。

S（椭圆面积）=PI(圆周率)×a（长半轴）×b（短半轴）
其中PI取3.14

输入格式:
圆心坐标、长半轴和短半轴的长度

输出格式：
椭圆的面积

输入样例：
1 1 1 2

输出样例：
6.28
*****************************************************************************************************************************/
#include <cmath>
#include <iostream>
using namespace std;
class Ellipse
{
private:
	int x1, y1, x2, y2;
public:
	Ellipse(int, int, double, double);
	double Area();
};
Ellipse::Ellipse(int a, int b, double c, double d) :x1(a), y1(b), x2(c), y2(d)
{}

double Ellipse::Area()
{
	return (double)abs( x2 * y2 ) * 3.14;
}
int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Ellipse e1(x1, y1, x2, y2);

	cout << e1.Area() << endl;

	return 0;
}
