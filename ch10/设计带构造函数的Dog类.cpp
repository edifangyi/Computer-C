/*****************************************************************************************************************************
设计一个Dog类，包含name、age、sex和weight等属性，在有参数的构造函数中对数据成员进行初始化。
公有成员函数有：GetName()、GetAge()、GetSex()和GetWeight()可获取名字、年龄、性别和体重。编写成员函数speak() 
显示狗的叫声。编写主函数，输入狗的名字、年龄、性别和体重；声明Dog对象并用输入的数据通过构造函数初始化对象，通过成员函数获取狗的属性并显示出来。

输入格式:
狗的信息

输出格式：
狗的信息，外加叫声

输入样例：
Tom 4 m 2.4

输出样例：
Tom
4
m
2.4
Arf!Arf!
*****************************************************************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;
class Dog
{
	char name[20];
	char sex;
	int age;
	float weight;
public:
	void Register(char * Name,int Age,char Sex,float Weight);
	char * GetName(){return name;}
	int GetAge(){return age;}
	char GetSex(){return sex;}
	float GetWeight(){return weight;}
	void Speak(){cout<<"Arf!Arf!"<<endl;}
};
void Dog::Register(char * Name,int Age,char Sex,float Weight)
{
	strcpy(name,Name);
	age=Age;
	sex=Sex;
	weight=Weight;
}
int main()
{
	char name[20];
	char sex;
	int age;
	float weight;
	Dog dog1;
	cin>>name>>age>>sex>>weight;
	dog1.Register(name,age,sex,weight);
	cout<<dog1.GetName()<<endl;
	cout<<dog1.GetAge()<<endl;
	cout<<dog1.GetSex()<<endl;
	cout<<dog1.GetWeight()<<endl;
        dog1.Speak();
	return 0;
}