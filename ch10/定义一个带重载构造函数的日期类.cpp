/*********************************************************************************************************
题目内容：
定义一个带重载构造函数的日期类Date，数据成员有年、月、日；成员函数包括：一个带参数的构造函数Date(int,int,int)，
一个不带参数的构造函数，一个按“年-月-日”格式显示日期的函数，一个对数据成员赋值的函数void init(int,int,int)。

主函数中对类的测试要求：
1.
分别使用两个不同的重载构造函数创建两个日期类对象（必须为d1,d2，d2初始值为2100-12-12）；
2.
按“年-月-日”格式分别显示两个对象的值；
3. 输入数据，用init函数为d1赋值；
2．按“年-月-日”格式显示对象d1的值；。

输入格式:
给d1赋值的数据

输出格式：
d1的默认值
d2的初始值
d1赋值后的值

输入样例：
2011 4 29

输出样例：
1900-1-1
2100-12-12
2011-4-29
**********************************************************************************************************/
*#include "iostream"
#include "cstring"
#include "string"
using namespace std;

class Date
{
private:
	int year;
	int mouth;
	int day;
public:
	Date();//构造函数0
	Date(int yy, int mm, int dd);//带参数的构造函数重载1
	void SetDate(int, int, int);
	void init(int, int, int);
	void print_ymd();
};

Date::Date()//构造函数0的定义
{
	year = 1900;
	mouth = 1;
	day = 1;
}

Date::Date(int yy, int mm, int dd)//构造函数1的定义
{
	year = yy;
	mouth = mm;
	day = dd;
}

void Date::init(int yy, int mm, int dd)//对数据成员赋值
{
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;
	mouth = (mm >= 1 && mm <= 12) ? mm : 1;
	day = (dd >= 1 && dd <= 31) ? dd : 1;
}

void Date::print_ymd()//按“年-月-日”格式显示日期
{
	cout << year << "-" << mouth << "-" << day << endl;
}

int main()
{
	Date d1,d2(2100,12,12);

	int year, mouth, day;
	cin >> year >> mouth >> day;
	
	d1.print_ymd();

	d2.print_ymd();//d2的初始值
	
	d1.init(year, mouth, day);//对数据成员赋值
	d1.print_ymd();//d1赋值后的值

	system("pause");
	return 0;
}