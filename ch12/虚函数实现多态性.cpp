/************************************************************
题目内容：
定义宠物类Pet，包含虚函数Speak，显示如下信息“How does a pet speak?”;
定义公有派生类Cat和Dog，其Speak成员函数分别显示：“miao! miao!”和“wang! wang!”。
主函数中定义Pet，Cat和Dog对象，再定义Pet指针变量，分别指向Pet，Cat和Dog对象，
并通过指针调用Speak函数，观察并分析输出结果。

输入格式:
不需要输入

输出格式：
各类调用Speak函数输出的结果

输入样例：


输出样例：
How does a pet speak?
miao!miao!
wang!wang!
*************************************************************/
#include <iostream>
using namespace std;
class pet
{
public:
	virtual void speak() { cout << "How does a pet speak?" << endl; }
};
class cat :public pet
{
public:
	void speak() { cout << "miao!miao!" << endl; }
};
class dog :public pet
{
	void speak() { cout << "wang!wang!" << endl; }
};

int main()
{
	pet *p1, *p2, obj;	//p为宠物类指针
	cat cat1;			//定义猫类对象
	dog dog1;			//定义狗类对象

	obj.speak();

	p1 = &cat1;
	p2 = &dog1;

	p1 = &cat1;
	p1->speak();	//输出1，执行猫对象地址付给p
	
	p2 = &dog1;
	p2->speak();
	return 0;
}