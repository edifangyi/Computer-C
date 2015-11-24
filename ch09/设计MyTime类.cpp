/*****************************************************************************************************************************
题目内容：
设计一个MyTime类，成员函数SetTime()设置时间，print_12()以12小时制显示时间（AM上午，PM下午），print_24()以24小时制显示时间。

输入格式:
所需设置时间的时、分、秒

输出格式：
按照12小时制和24小时制依次显示时间,注意时间格式中的冒号是英文冒号

输入样例：
13 23 34

输出样例：
01:23:34 PM
13:23:34
*****************************************************************************************************************************/



#include <cmath>
#include <iostream>
using namespace std;

class MyTime 
{
	int hour, minute, second;
public:
	MyTime(int h = 0, int m = 0, int s = 0);
	void SetTime(int,int,int);
	void print_12();
	void print_24();
};

MyTime::MyTime(int h, int m, int s) 
{
	SetTime(h, m, s); 
}
void MyTime::SetTime(int hh, int mm, int ss)
{
	hour = (hh >= 0 && hh <= 23) ? hh : 0;
	minute = (mm >= 0 && mm <= 59) ? mm : 0;
	second = (ss >= 0 && ss <= 59) ? ss : 0;
}

void MyTime::print_12()
{
	int hh = (hour == 0 || hour == 12) ? 0 : hour % 12;
	cout << ((hour < 10) ? "0" : "") << hh << ":"
		<<((minute < 10) ? "0" : "") << minute << ":"
		<< ((second < 10) ? "0" : "") << second
		<< (hour < 12 ? " AM" : " PM");
}

void MyTime::print_24()
{
	cout << ((hour < 10) ? "0" : "") << hour << ":"
		<< ((minute < 10) ? "0" : "") << minute << ":"
		<< ((second < 10) ? "0" : "") << second;
	cout << endl;

}




int main()
{
	MyTime t2;
	int s, h, m;
	cin >> h >> m >> s;
	t2.SetTime(h, m, s);
	t2.print_12();
	cout<< endl;
	t2.print_24();

	return 0;
}