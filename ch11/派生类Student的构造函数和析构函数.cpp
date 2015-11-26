/*****************************************************************************************************************************
题目内容：
已知基类Person的定义如下：
class Person
{ 
	char Name[10]; //姓名
	int Age; //年龄
public:
	Person(char* name,int age)
	{ 
		strcpy(Name, name);
		Age = age;
		cout<<"constructor of person"<<Name<<endl; 
	}
	~Person()
	{ 
		cout<<"deconstrutor of person"<<Name<<endl;
	}
};
请通过继承的方法建立一个派生类Student，其中
1．新增的数据成员有：
char ClassName[10]; //班级
Person Monitor; //班长
2．新增的成员函数有：
Student(char *name, int age, char *classname, char *name1, int age1) //name1和age1是班长的信息
~Student()
在主程序中建立一个派生类对象。

输入格式:
Student类的初始化信息

输出格式：
派生类和基类构造函数和析构函数输出的信息，请参考输出样例的格式。

输入样例：
张弓长 18 计算机51 李木子 20

输出样例：
constructor of person张弓长
constructor of person李木子
constructor of Student
deconstrucor of Student
deconstrutor of person李木子
deconstrutor of person张弓长
*****************************************************************************************************************************/
#include <iostream>
#include<cstring>
using namespace std;
class Person
{
	char Name[10]; //姓名
	int Age; //年龄
	public:
		Person(char* name,int age)//构造函数 
		{ 
			strcpy(Name, name);
			Age = age;
			cout<<"constructor of person"<<Name<<endl; 
		}
		~Person()//析构函数 
		{ 
			cout<<"deconstrutor of person"<<Name<<endl; 
			
		}
};
class Student:public Person//公有继承方式 
{
	char ClassName[10]; //班级
	Person Monitor; //班长
	public:
		Student(char *name, int age, char *classname, char *name1, int age1)
		:Person(name,age),Monitor(name1,age1) //name1和age1是班长的信息
		{//派生类构造函数
			strcpy(ClassName, classname);
			cout<<"constructor of Student"<<endl;
		}
	 	~Student()
		{
		 	cout<<"deconstrucor of Student"<<endl;
			}	
};
int main()
{
	char name[10]; //基类数据，
	int age;//基类数据，
	char classname[10];
	char name1[10];
	int age1;
	cin>>name;cin>>age;cin>>classname;cin>>name1;cin>>age1;
	Student stu1(name,age,classname,name1,age1);
    return 0;
}