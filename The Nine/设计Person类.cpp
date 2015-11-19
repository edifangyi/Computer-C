/***********************************************************************************************
题目内容：
设计一个Person类，包含name、age、sex属性以及对这些属性操作的方法。实现并测试这个类。
根据类的封装性要求，把name、age、sex声明为私有的数据成员，声明公有的成员函数Register()
、ShowMe()来访问这些属性，在Register()函数中对数据成员进行初始化。person1通过cin来得到信息，
person2通过Register("Zhang3", 19, 'm') 来得到信息。

输入格式:
person1的信息

输出格式：
person1和person2的信息

输入样例：
Li4 18 f

输出样例：
Li4 18 f
Zhang3 19 m
***********************************************************************************************/
#include "iostream"
#include "cstring"

using namespace std;

class Person
{
private:
	char Name[20];
	char Sex;
	int Age;
public:
	void Register(char *name, int age, char sex);
	void ShowMe();
};

void Person::Register(char *name, int age, char sex)
{
	strcpy(Name, name);
	Age = age;
	Sex = (sex == 'm' ? 'm' : 'f');
}
void Person::ShowMe()
{
	cout << Name << " " << Age << " " << Sex << endl;
}

int main()
{
	char name[20],sex;
	int age;
	Person person1, person2;
	cin >> name >> age >> sex;
	person1.Register(name, age, sex);
	person1.ShowMe();
	person1.Register("Zhang3", 19,'m');
	person2 = person1;
	person2.ShowMe();
	
	
	return 0;
}