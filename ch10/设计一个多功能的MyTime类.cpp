/*****************************************************************************************************************************
题目内容：
设计一个多功能的MyTime类，设计多个重载的构造函数，可以设置时间，进行时间的加减运算，按各种可能的格式（24小时制、12小时制）输出时间。
注意：
（1）请考虑设置的时间的合理性（时0-23； 分0-59；秒0-59）。
（2）12小时制中，12:00:00前为AM， 12:00:00及以后为PM
（3）加减运算的加数、减数是一个时间的长度，单位为“时、分、秒”
（4）构造函数：没参数时，设置时间为0时 0分 0秒；有参数时，设置成给定的时、分、秒。
 在主函数中
（1）声明两个对象t1,t2，并通过构造函数初始化它们（t2初始化为为8：10：30）
（2）显示按12、14小时制显示t1、t2的时间。
（3）再设置t1的时间，数据由用户输入。
（4）再输入待加减的时间。
（5）t1加输入的时间，并按12小时和24小时制显示。
（6）t2减输入的时间，并按12小时和24小时制显示。

输入格式:
第一行为t1的时间，第二行为待加减的时间

输出格式：
显示按12、14小时制显示t1、t2的初始时间
t1加输入的待加减的时间按12小时和24小时制显示。
t2减输入的待加减的时间按12小时和24小时制显示

输入样例：
11 30 30
5 15 20

输出样例：
00:00:00 AM
00:00:00
08:10:30 AM
08:10:30
04:45:50 PM
16:45:50
02:55:10 AM
02:55:10
*****************************************************************************************************************************/



#include <cmath>
#include <iostream>
using namespace std;
class Time
{
	int hour, minute, second;
public:
	int SecCalc();
	Time(int h = 0, int m = 0, int s = 0);
	void SetTime(int h = 0, int m = 0, int s = 0);
	void print_12();
	void print_24();
	void print_hms();
	Time operator+(Time&);
	Time operator-(Time&);
};
Time::Time(int h, int m, int s) { SetTime(h, m, s); }
void Time::SetTime(int hh, int mm, int ss)
{
	hour = (hh >= 0 && hh <= 23) ? hh : 0;
	minute = (mm >= 0 && mm <= 59) ? mm : 0;
	second = (ss >= 0 && ss <= 59) ? ss : 0;
}
void Time::print_24()
{
	cout << ((hour < 10) ? "0" : "") << hour << ":"
		<< ((minute < 10) ? "0" : "") << minute << ":"
		<< ((second < 10) ? "0" : "") << second;
	cout << endl;

}
void Time::print_12()
{
	int hh = (hour == 0 || hour == 12) ? 0 : hour % 12;
	cout << ((hh < 10) ? "0" : "") << hh << ":"
		<< ((minute < 10) ? "0" : "") << minute << ":"
		<< ((second < 10) ? "0" : "") << second
		<< (hour < 12 ? " AM" : " PM");
}
void Time::print_hms()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

int Time::SecCalc()
{
	return(hour * 60 + minute) * 60 + second;
}
Time Time::operator+(Time& t3)
{
	Time tmp;
	int ss;
	ss = SecCalc() + t3.SecCalc();	
	tmp.hour = ss / 3600 % 24;
	tmp.minute = ss % 3600 / 60;
	tmp.second = ss % 3600 % 60;
	return tmp;
}
Time Time::operator-(Time& t3)
{
	Time tmp;
	int ss;
	int cc = t3.SecCalc();
	if (SecCalc() > cc)
	{
		ss =  abs(SecCalc() - t3.SecCalc());
		tmp.hour = (ss / 3600 % 24);
		tmp.minute = ss % 3600 / 60;
		tmp.second = ss % 3600 % 60;
	}
	else
	{
		ss = abs(SecCalc() - t3.SecCalc());
		tmp.hour = 23-(ss / 3600 % 24);
		tmp.minute = ss % 3600 / 60;
		tmp.second = ss % 3600 % 60;
	}
	return tmp;
}
int main()
{
	Time t1, t2(8, 10, 30), t3;


	int s, h, m;
	cin >> h >> m >> s;

	int s1, h1, m1;
	cin >> h1 >> m1 >> s1;



	t1.print_12();
	cout << endl;
	t1.print_24();

	t2.print_12();
	cout << endl;
	t2.print_24();

	t1.SetTime(h, m, s);
	t3.SetTime(h1, m1, s1);

	(t1 + t3).print_12();
	cout << endl;
	(t1 + t3).print_24();

	(t2 - t3).print_12();
	cout << endl;
	(t2 - t3).print_24();

	system("pause");
	return 0;
}