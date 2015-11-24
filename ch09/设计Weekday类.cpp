/*************************************************************************************************
题目内容：
设计一个Weekday类，成员函数SetDay()设置星期几，IncDay()前进一天，NowDay()打印当前是星期几。

输入格式:
用户输入一个数字，0表示星期日，1表示星期一，类推，6表示星期六，用该数字初始化Weekday类

输出格式：
使用中文打印出从当日起连续3天是星期几

输入样例：
0

输出样例：
星期日
星期一
星期二
*************************************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;

class Weekday
{
	int week;
public:
	Weekday(int d=0);
	void SetDay(int);
	void IncDay();
	void NowDay();
};

Weekday::Weekday(int d)
{
	SetDay(d);
}

void Weekday::SetDay(int dd)
{
	week = dd;
}

void Weekday::NowDay()
{
	switch (week)
	{
	case 1:cout << "星期一" << endl;break;
	case 2:cout << "星期二" << endl;break;
	case 3:cout << "星期三" << endl;break;
	case 4:cout << "星期四" << endl;break;
	case 5:cout << "星期五" << endl;break;
	case 6:cout << "星期六" << endl;break;
	case 0:cout << "星期日" << endl;break;
	}
}

void Weekday::IncDay()
{
	if (week >= 0 && week <= 4)
	{
		static int f = week;
		for (int i = 0;i < 2;i++)
		{
			switch (++f)
			{
			case 1:cout << "星期一" << endl;break;
			case 2:cout << "星期二" << endl;break;
			case 3:cout << "星期三" << endl;break;
			case 4:cout << "星期四" << endl;break;
			case 5:cout << "星期五" << endl;break;
			case 6:cout << "星期六" << endl;break;
			}
		}
	}
	else if (week == 5) {
		cout << "星期六" << endl;
		cout << "星期日" << endl;
	}
	else {
		cout << "星期日" << endl;
		cout << "星期一" << endl;
	}
}

int main()
{
	Weekday day1;
	int day;
	cin >> day;
	day1.SetDay(day);
	day1.NowDay();
	day1.IncDay();

	return 0;
}