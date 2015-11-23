/************************************************************
数据成员：分子分母
	整型变量：int a，b;
	分子、分母定义成公有、私有、保护理论上都可以
	根据抽象封装原理，数据成员应该定义为私有成员
成员函数：设置数据、输出分数、+、==、求最大公因数、求负等
	void set(int aa,int bb);//设置分子分母
	void show();//显示分数
	Fraction add(Fraction b);//加一个分数
	Fraction operator+(Fraction b);//运算符+重载
	bool operator==(Fraction b);//运算符==重载
	Fraction operator-();//求负运算符-重载
	int divisor(int p,int q);//求最大公约数
*************************************************************/


#include "iostream"
#include "cstring"
using namespace std;

class Fraction
{
	int a;//分子
	int b;//分母
	int divisor(int p, int q);		//求最大公约数
public:
	Fraction(){a = 0;b = 1;}		//无参构造函数
	Fraction(int, int);				//有参构造函数
	void set(int aa, int bb);		//设置分子分母
	void show();					//显示分数
	Fraction add(Fraction b);		//加一个分数
	Fraction operator+(Fraction u);	//运算符+重载
	bool operator==(Fraction u);	//运算符==重载
	Fraction operator-();			//求负运算符-重载
	~Fraction() {};					//析构函数
};

Fraction::Fraction(int x, int y)
{
	set(x, y);
}
void Fraction::set(int aa, int bb)
{
	a = aa;
	if (bb != 0) //分母有效性检验
		b = bb;
	else
	{
		a = 0;
		b = 1;
	}
}
void Fraction::show()
{
	cout << a << "/" << b;
}
Fraction Fraction::add(Fraction u)
{
	int tmp;
	Fraction v;
	v.a = a*u.b + b*u.a;	//分子
	v.b = b*u.b;	//分母
	tmp = divisor(v.a, v.b);	//计算分子、分母公约数
	v.a = v.a / tmp;	//约去公约数
	v.b = v.b / tmp;	//约去公约数
	return v;
}
Fraction Fraction::operator+(Fraction u)
{
	int tmp;
	Fraction v;
	v.a = a*u.b + b*u.a;	//分子
	v.b = b*u.b;	//分母
	tmp = divisor(v.a, v.b);	//计算分子、分母公约数
	v.a = v.a / tmp;	//约去公约数
	v.b = v.b / tmp;	//约去公约数
	return v;
}
bool Fraction::operator==(Fraction u)
{
	float x, y;
	x = (float)a / b;
	y = (float)u.a / u.b;
	if (x == y)
		return true;
	else
		return false;
}
Fraction Fraction::operator-()
{
	a = a*(-1);
	return *this;
}
int Fraction::divisor(int p, int q)
{
	int r;
	if (p < q)
	{
		int tmp;
		tmp = p;
		p = q;
		q = tmp;
	}
	r = p%q;
	while (r != 0)
	{
		p = q;
		q = r;
		r = p%q;
	}
	return q;
}

int main()
{
	Fraction f1, f2, f3;
	f1.set(4, -5);
	cout << "f1=";
	f1.show();
	cout << endl;
	f2.set(3, 6);
	cout << "f2=";
	f1.show();
	cout << endl << endl;

	cout << "f2 = f1 + f2 = ";
	f1.show();
	cout << " + ";
	f2.show();
	f3 = f1 + f2;
	cout << " = ";
	f3.show();
	cout << endl << endl;
	cout << "f1=";
	f1.set(6, -20);
	f1.show();
	cout << endl << endl;
	
	if (f1 == f3)
		cout << "\nf1==f3" << endl;
	else
		cout << "\nf1!=f3" << endl;
	
	f2 = (-f2);
	//-f2; //也正确
	cout << " -f2= ";
	f2.show();
	system("pause");
	return 0;
}