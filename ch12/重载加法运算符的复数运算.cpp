/*******
题目内容：
定义一个复数类，并重载加法运算符（+）和赋值运算符（=）以适用对复数运算的要求。

输入格式:
依次输入两个复数的实部和虚部

输出格式：
先按照要求格式输出两个复数，然后输出这两个复数的和

输入样例：
1 2
3 4

输出样例：
1+j2
3+j4
4+j6
*******************************************************************/
*#include <iostream>
#include "cstring"
using namespace std;
class Complex
{
	double real, imag;
public:
	Complex(double r=0,double i=0):real(r),imag(i){}
	double Real() { return real; }
	double Imag() { return imag; }
	Complex operator +(Complex &);
	Complex operator +(double);
	Complex operator =(Complex);
};
Complex Complex::operator+(Complex &c)//重载运算符 +
{
	Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}

Complex Complex::operator+(double d)//重载运算符 +
{
	Complex temp;
	temp.real = real + d;
	temp.imag = imag;
	return temp;
}
Complex Complex::operator=(Complex c)//重载运算符 =
{
	Complex temp;
	temp.real = c.real;
	temp.imag = c.imag;
	return *this;
}


int main()
{
	//Complex c1(3.4), c2(5, 6), c3;
	double x1, y1;
	double x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Complex c1(x1, y1);
	Complex c2(x2, y2);
	Complex c3 = c1 + c2;
	cout << c1.Real() << "+j" << c1.Imag() << endl;
	cout << c2.Real() << "+j" << c2.Imag() << endl;
	cout << c3.Real() << "+j" << c3.Imag() << endl;
	system("pause");
	return 0;
}