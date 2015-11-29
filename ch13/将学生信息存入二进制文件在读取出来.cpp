/**************************************************************
建立学生信息类，包含姓名/班级/性别/年龄四个私有属性。有构造函数
/输出自身信息的函数。在主函数中创建3个对象，而后按二进制形式存入
文件，最后再读出该文件信息并显示。
**************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	char Name[10];
	char Class[10];
	char Sex;
	int Age;
public:
	Student(){}
	Student(char *Name, char *Class, char sex, int age)
	{
		strcpy_s(this->Name, Name);
		strcpy_s(this->Class, Class);
		Sex = sex;
		Age = age;
	}
	void Showme()
	{
		cout << Name << '\t' << Class << '\t' << Sex << '\t' << Age << endl;
	}
};

int main()
{
	Student stu[3] = {
		Student("王小二", "电气11", 'm', 27),
		Student("刘大明", "机械01", 'f', 24),
		Student("李文华", "生物12", 'm', 39)
	};
	//打开文件
	ofstream file1("file.dat", ios::binary);
	if (!file1)
	{
		cout << "文件打开失败!";
		return 1;
	}
	//写文件
	for (int i = 0;i < 3;i++)
		file1.write((char*)&stu[i], sizeof(stu[i]));
	file1.close();//关闭文件

	///////////////以下为读文件并显示出来//////////////
	Student stu2;//建立对象
	ifstream file2("file.dat", ios::binary);
	if (!file2)
	{
		cout << "文件打开失败！";
		return 1;
	}
	//读文件
	while (file2)
	{
		file2.read((char*)&stu2, sizeof(stu2));
		if (file2)
			stu2.Showme();
	}
	//关闭文件
	file2.close();

	system("pause");
	return 0;
}