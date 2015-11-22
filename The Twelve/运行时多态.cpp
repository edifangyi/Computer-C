#include <iostream>
using namespace std;
class pet
{
public:
	virtual void speak(){cout <<"zzz"<<endl;}
};
class cat:public pet
{
public:
	void speak(){cout<<"miao!miao!"<<endl;}
};
class dog:public pet
{
	void speak(){cout<<"wang!wang!"<<endl;}
}

void main()
{
	pet pet1,*p=&pet1;	//p为宠物类指针
	cat cat1;			//定义猫类对象
	dog dog1;			//定义狗类对象
	int x;				//根据用户输入将猫或狗对象地址赋给P指针
	cin>>x;				//
	if(x==1) p=&cat1;	//输出1，执行猫对象地址付给p
	if(x==2) p=%dog1;
	p->speak();
}