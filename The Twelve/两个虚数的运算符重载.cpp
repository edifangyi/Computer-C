/************************************************************
首先定义虚数类
虚数可以描述为：a+bi
	a与b看成实数，定义为double类型
成员函数除了构造与析构外，还有：
	输出虚数、修改虚数、得到实部a、得到虚部b
	相加+、判相等==
*************************************************************/


#include "iostream"
#include "cstring"
using namespace std;

class Complex
{
private:
	double real, imag;
public:
	Complex(double r=0,double i=0):real(r),imag(i){}
	double Real() { return real; }
	double Imag() { return imag; }

	Complex operator +(Complex&);
	Complex operator +(double);
	
	Complex operator ++();
	Complex operator ++(int)
	bool operator ==(Complex);
	~Complex() {};
};
Complex Complex::operator+(Complex &c)	//重载运算符 +，两边是虚数对象
{
	Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}
Complex Complex::operator+(double d)	//重载运算符 +，左边是虚数对象，右边是双精度数
{
	Complex temp;
	temp.real = real + d;
	temp.imag = imag;
	return temp;
}
bool Complex::operator==(Complex c)		//重载运算符==
{
	if (real == c.real&&imag == c.imag)
		return true;
	else
		return false;
}

//前置运算符定义++
Complex Complex::operator++()
{
	real += 1;
	return *this;
}
//后置运算符定义++
Complex Complex::operator++(int)
{
	real += 1;
	return *this;
	//Complex t;//另一种实现
	//t.real = real;
	//t.imag = imag;
	//real = real + 1;
	//return t;	//返回加1之前的对象
}





int main()
{
	Complex c1(3.4), c2(5, 6), c3;
	cout << "C1 =" << c1.Real() << "+j" << c1.Imag() << endl;
	system("pause");
	
	cout << "C2 =" << c1.Real() << "+j" << c2.Imag() << endl;
	system("pause");
	
	c3 = c1 + c2;
	cout << "C3 =" << c3.Real() << "+j" << c3.Imag() << endl;
	system("pause");
	
	c3 = c3 + 6.5;
	cout << "C3 + 6.5 =" << c3.Real() << "+j" << c3.Imag() << endl;
	if (c1==c2)
		cout << "两个负数相等";
	else
		cout << "两个复数不相等";
	system("pause");
	
	++c1;
	cout << "++C1" << c1.Real() << "+j" << c1.Imag() << endl;
	system("pause");

	c2++;
	cout << "C2++" << c1.Real() << "+j" << c1.Imag() << endl;




	system("pause");
	return 0;
}