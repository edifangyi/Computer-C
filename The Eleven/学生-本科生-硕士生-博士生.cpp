/*********************************************************************
设计一个学生类Student，由它一次派生出本科生CollegeStudent、
硕士生GraduateStudent和博士生DoctorStudentlei类

学生类包括好Stdno、姓名name、姓名age、班级classname和校名shoolname
等变量以及显示特征信息show函数

本科生类新增辅导员classteacher变量以及显示特征信息Show函数

硕士生类新增导师tutor和课题projectname变量以及显示特征信息Show函数

博士生类新增研究题目researchname变量以及显示特征信息Show函数

要求初始化并显示各类对象的信息

成员变量：每个派生类都增加一些；
成员函数：构造函数/输出信息函数Show
*********************************************************************/

#include "iostream"
#include "cstring"
using namespace std;


/*******************************基础类：学生类*******************************/
class Student
{
	int stdno;				//学号
	char name[20];			//姓名
	int age;				//年龄
	char classname[20];		//班级
	char schoolname[20];	//校名
public:
	Student(int stdno, char name[], int age, char classname[], char schoolname[])
	{
		this->stdno = stdno;
		strcpy_s(this->name,name);
		this->age = age;
		strcpy_s(this->classname, classname);
		strcpy_s(this->schoolname, schoolname);
	}
	void show()		//显示信息
	{
		cout << stdno << "\t";
		cout << name << "\t";
		cout << age << "\t";
		cout << classname << "\t";
		cout << schoolname << endl;
	}
};

/*******************************派生类：本科生类*******************************/
class CollegeStudent :public Student
{
private:
	char classteacher[20];		//辅导员
public:
	CollegeStudent(int stdno, char name[], int age, char classname[], char schoolname[],
		char classteacher[]) :Student(stdno, name, age, classname, schoolname)
	{
		strcpy_s(this->classteacher, classteacher);
	}
	void show()		//显示信息
	{
		Student::show();
		cout << classteacher << endl;
	}
};

/*******************************派生类：硕士生类*******************************/
class GraduateStudent :public CollegeStudent
{
private:
	char tutor[20];		//导师
	char projectname[50];	//课题
public:
	GraduateStudent(int stdno, char name[], int age, char classname[], char schoolname[],
		char classteacher[], char tutor[], char projectname[]) :
		CollegeStudent(stdno, name, age, classname, schoolname, classteacher)
	{
		strcpy_s(this->tutor, tutor);
		strcpy_s(this->projectname, projectname);
	}
	void show()		//显示信息
	{
		CollegeStudent::show();
		cout << tutor << "\t";
		cout << projectname << endl;
	}
};

/*******************************派生类：博士生类*******************************/ 
class DoctorStudentlei :public GraduateStudent
{
private:
	char researchname[50];	//研究题目
public:
	DoctorStudentlei(int stdno, char name[], int age, char classname[], char schoolname[],
		char classteacher[],char tutor[], char projectname[], char researchname[]) :
		GraduateStudent(stdno, name, age, classname, schoolname, classteacher, tutor, projectname)
	{
		strcpy_s(this->researchname, researchname);
	}
	void show()		//显示信息
	{
		GraduateStudent::show();
		cout << researchname << endl;
	}
};


int main()
{
	int stdno;
	char name[20];
	int age;
	char classname[20];
	char schoolname[20];
	cout << "input the information of student:" << endl;
	cin >> stdno >> name >> age >> classname >> schoolname;
	Student student1(stdno, name, age, classname, schoolname);
	cout << "the information of student is:" << endl;
	student1.show();
	char classteacher[20];
	cout << "input the information of collegestudent:" << endl;
	cin >> classteacher[20];
	CollegeStudent student2(stdno, name, age, classname, schoolname, classteacher);
	cout << "the information of collegestudent is:" << endl;
	student2.show();
	char tutor[20];
	char projectname[50];
	cout << "input the information of graduatestudent:" << endl;
	cin >> tutor >> projectname;
	GraduateStudent student3(stdno, name, age, classname, schoolname, classteacher, tutor, projectname);
	cout << "the information of graduatestudent is:" << endl;
	student3.show();
	char researchname[50];
	cout << "input the information of doctorstudent:" << endl;
	cin >> researchname;
	DoctorStudentlei student4(stdno, name, age, classname, schoolname, classteacher, tutor, projectname, researchname);
	cout << "the information of doctorStudentlei is:" << endl;
	student4.show();
	system("pause");
	return 0;
}