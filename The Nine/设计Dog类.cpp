/************************************************************************************************
设计一个Dog类，包含name、age、sex和weight等属性以及对这些属性操作的方法。实现并测试这个类。
根据类的封装性要求，把name、age、sex和weight声明为私有的数据成员，编写公有成员函数setdata()
对数据进行初始化，GetName()、GetAge()、GetSex()和GetWeight()获取相应属性。初始化数据由用户输入。

输入格式:
Dog类对象的初始化数据

输出格式：
根据Dog类对象的初始化数据输出一句话，请严格按照格式输出。

输入样例：
ahuang 3 m 2.4

输出样例：
It is my dog.
Its name is ahuang.
It is 3 years old.
It is male.
It is 2.4 kg.
************************************************************************************************/
#include "iostream"
#include "cstring"

using namespace std;

class Dog
{
	char name[20];
	char sex;
	int age;
	float weight;
public:
	void Register(char *Name, int Age, char Sex,float Weight);
	char *GetName() { return name; }
	int GetAge() { return age; }
	char GetSex() { return sex; }
	float GetWeight() { return weight; }
};

void Dog::Register(char *Name, int Age, char Sex,float Weight)
{
	strcpy(name, Name);
	age = Age;
	sex = (Sex == 'm' ? 'm' : 'f');
	weight = Weight;
}



int main()
{
	char name[20];
	char sex;
	int age;
	float weight;
	Dog dog1;
	cin >> name >> age >> sex >> weight;
	dog1.Register(name, age, sex, weight);
	cout << "It is my dog." << endl;
	cout << "Its name is " << dog1.GetName() << "." << endl;
	cout << "It is " << dog1.GetAge() << " years old." << endl;
	cout << "It is " << dog1.GetSex() << "ale." << endl;
	cout << "It is " << dog1.GetWeight() << " kg." << endl;

}