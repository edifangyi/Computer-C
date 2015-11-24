#include <iostream>
using namespace std;
class pet
{
public:
	virtual void speak(){cout <<"How does a pet speal?"<<endl;}
};
class cat:public pet
{
public:
	void speak(){cout<<"miao!miao!"<<endl;}
};
class dog:public pet
{
	void speak(){cout<<"wang!wang!"<<endl;}
};

void main()
{
	pet *p1,*p2,*p3,obj;//基类对象指针盘，基类对象obj
	dog dog1;
	cat cat1;

	obj =dog1;			//用dog类对象给Pet类对象赋值
	obj.speak();

	p1=&cat1;			//用Cat类对象地址给基类指针赋值
	p1->speak();
	p1=&dog1;			//用dog类对象地址给基类指针赋值
	p1->speak();

	p2=new cat;			//动态生成Cat类对象
	p2->speak();
	p3=new dog;			//动态生成dog类对象
	p3->speak();

	pet &p4=cat1;		//以Cat类对象初始化Pet类引用
	p4.speak();
	return 0;
}