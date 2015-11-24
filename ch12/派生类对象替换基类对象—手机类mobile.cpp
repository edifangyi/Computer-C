/*********************************************************************
派生类对象替换基类对象—手机类mobile

设计一个手机类moblie，使其能派生出两种发射制式（GSM或者CSMA）
的手机类mobilegsm和mobliecdma
	
派生类对象能够依据各自特征实现显示发射制式的功能，并实现运行
时的动态绑定。
	通过将基类对象或者指针在运行时指向不同的派生类对象实现动
	态绑定。
*********************************************************************/

#include <iostream>
using namespace std;

//一个基类与两个派生类的定义
class mobile
{
public:
	mobile(){}
	char mynumber[11];	//机主的电话号码
	void showinfo()		//显示制式
	{
		cout<<"The phone is mobile"<<endl;
	}
};
class mobilegsm:public mobile
{
public:
	mobilegsm(){}
	void showinfo();	//显示制式
	{
		cout<<"The phone is mobilegsm"<<endl;
	}
};
class mobilecdma:public mobile
{
public:
	mobilecdma(){}
	void showinfo()		//显示制式
	{
		cout<<"The phone is mobilecdma"<<endl;
	}
};

int main()
{
	mobile m,*p1;		//基类对象指针p1，基类对象m
	mobilegsm gsm;
	mobilecdma cdma;
	m=gsm;				//用gsm类对象给mobile类对象赋值
	m.showinfo();
	m=cdma;
	m.showinfo();
	p1=&gsm;			//用gsm类对象地址给mobile类对象赋值
	p1->showinfo();
	p1=&cdma;
	p1->showinfo();
	mobile &p4=gsm;		//以gsm类对象初始化mobile类引用
	p4.showinfo();
	mobile &p5=cdma;
	p5.showinfo();
	return 0;
}