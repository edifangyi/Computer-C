/*****************************************************
题目内容：
输入一个正整数。计算其平方根(用sqrt函数)，并将结果按取1~6位小数分六行显示出来。

输入格式:
输入一个正整数。

输出格式：
计算结果分6行显示，小数位数依次取1~6位。

输入样例：
2

输出样例：
1.4
1.41
1.414
1.4142
1.41421
1.414214
*****************************************************/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


int main()
{
	double num;
	cin >> num;
	 double sum;
	sum = sqrt(num);
	for (int i = 1;i < 7; i++)
	{
		cout << setiosflags(ios::fixed)<< setprecision(i) << sum << endl;
	}
	return 0;
}