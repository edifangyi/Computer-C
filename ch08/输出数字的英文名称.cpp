/********************************************************
题目内容：
编写一个函数，将表示数字的数值（1-12）转换成对应的英文名称（小写）。用户输入阿拉伯数字，程序输出对应数字的英文单词。要求必须使用指针数组完成。

输入格式:
1-12的数字

输出格式：
输入数字对应的英文单词，均为小写字母

输入样例：
1

输出样例：
one
*********************************************************/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char *nums(int n)
{
	static char *num[] = { "one","two","three","four","five",
		"six","seven","eight","nine","ten",
		"eleven","twelve","thirteen" };
	return num[n-1];
}

int main()
{
	int n;
	cin >> n;
	cout << nums(n);
}