/****************************************************************************
有四个学生信息文本文件，内容分别如下
	第一个文件是学号/姓名/班级等基本信息；
	第二个文件是学号和高数成绩；
	第三个文件是学号和英语成绩；
	第四个文件是学号和计算机成绩；
请将这些文件按学号匹配合并为一个新的文本文件，新文件和每行内容如下：
	学生学号、姓名、班级、高数成绩、英语成绩、计算机成绩和平均成绩
算法分析：
①定义学号、姓名等变量；
②分别以读方式打开四个原始数据文件和以写方式打开一个目标文件；
③循环从四个原始文件中一次读取学号、姓名等信息，并计算平均成绩。读取出错时转⑤；
④将这些信息写入目标文件中，转③
⑤关闭所有文件。
****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Student
{
public:
	int no;				//学号
	string name;		//姓名
	string classname;	//班级
	float math;			//高数成绩
	float english;		//英语成绩
	float computer;		//计算机成绩
	float average;		//平均成绩
};
float getscore(string filename, int stdno);
ostream & operator<<(ostream & out, Student & student);
int main()
{
	ifstream in("info.txt");
	ofstream out("student.txt");

	if (!in || !out)
	{
		cout << "文件打开错误" << endl;
		return 1;
	}
	out << "学号\t\t姓名\t班级\t高数\t英语\t计算机\t平均" << endl;
	while (in)
	{
		Student student;
		in >> student.no >> student.name >> student.classname;
		if (!in)
		{
			break;
		}
		student.math = getscore("math.txt", student.no);
		student.english = getscore("english.txt", student.no);
		student.computer = getscore("computer.txt", student.no);
		student.average = (student.math + student.english + student.computer)/3;

		out << student;
	}
	out.close();
	in.close();
	cout << "student.txt文件建立成功，请查阅！" << endl;
	//system("pause");
	return 1;
}

float getscore(string filename, int stdno)
{
	int stdno_temp;
	float score;
	ifstream in(filename.c_str());
	if (!in)
	{
		cout << "文件打开错误。" << endl;
		return 0;
	}
	bool flag = false;
	while (in)
	{
		in >> stdno_temp >> score;
		if (in)
		{
			if (stdno_temp==stdno)
			{
				flag = true;
				break;
			}
		}
	}
	if (!flag)
	{
		score = 0;
	}
	in.close();
	return score;
}

ostream & operator<<(ostream & out , Student & student)
{
	out << student.no << '\t' << student.name << '\t' << student.classname;
	out << '\t' << student.math;
	out << '\t' << student.english;
	out << '\t' << student.computer;
	out << '\t' << student.average;
	out << endl;
}