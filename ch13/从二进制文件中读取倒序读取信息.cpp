/**************************************************************
读取学生信息文件，并且从最后一个记录倒序读出并输出
**************************************************************/
/**************************************************************
读取学生信息文件，并且从最后一个记录倒序读出并输出
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
	Student() {}
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
	Student stu;//建立对象
	//打开文件
	ifstream file("file.dat", ios::binary);
	if (!file)
	{
		cout << "文件打开失败!";
		return 1;
	}
	file.seekg(0, ios::end);//定位文件指针到文件尾
	int len = file.tellg();	//得到文件指针位置（文件大小）

	//读文件
	for (int k = len / sizeof(stu) - 1;k >= 0;k--)//k从2开始
	{
		file.seekg(k*sizeof(stu));//最后一个人的起始位置
		file.read((char*)&stu, sizeof(stu));//按字节形式都出来
		stu.Showme();
	}
	system("pause");
	return 0;
}