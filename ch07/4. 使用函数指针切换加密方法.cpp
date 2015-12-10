/********************************************************
题目内容：
编写两个加密函数，第一个函数使用凯撒加密法，即将将原来的小写字母用字母表中其后面的第3个字母的大写形式来替换，大写字母按同样规则用小写字母替换，可将字母表看成是首末衔接的。例如"AMDxyzXYZ" 加密为 "dpgABCabc"。第二个函数使用单双号加密法，即将字符串"abcde",根据单双号区分为两个字符串"ace"和"bd"，再连接在一起成为密文"acebd"。
用户输入一个字符串作为明文，再输入数字1或2，输入1使用第一个函数加密并输出密文，输入2使用第二个函数加密并输出密文。要求使用函数指针来切换加密函数。

提示：三个函数的原型可设为：
void caesar(char s[]);
void oddeven(char s[]);
void cipher(void (*f)(char s[]),char s[]);//形参为指向函数的指针，对应实参可为相应格式的函数名。


输入格式:
一个字符串作为明文，再输入数字1或2，输入1使用第一个函数加密并输出密文，输入2使用第二个函数加密并输出密文。

输出格式：
加密后的密文

输入样例：
jacky
2

输出样例：
jcyak
时间限制：500ms内存限制：32000kb
*********************************************************/
#include <iostream>
#include <string>
#include <ctype.h>
#include "cmath"
using namespace std;


void caesa(char s[])
{
	for (int i = 0;s[i] != '\0';i++) 
	{
		
		if (s[i] <= 'z'&& s[i] >= 'a') {
			s[i] = (char)((s[i] - 'a' + 3) % 26 + 'A');
		}
		else {
			if (s[i] <= 'Z'&& s[i] >= 'A') {
				s[i] = (char)((s[i] - 'A' + 3) % 26 + 'a');
			}
		}
	}
}

void oddeven(char s[])
{
	char a[100], b[100];
	int i = 0, j = 0, k = 0;
	while (s[i] != '\0') {
		a[j] = s[i];
		j++;
		if (s[i + 1] != '\0') {
			b[k] = s[i + 1];
			k++;
		}
		else
			break;
		i += 2;
	}
	for (i = 0;i < j;i++)
		s[i] = a[i];
	for (i = 0;i < k;i++)
		s[i + j] = b[i];
	s[j + k] = '\0';
}

void cipher(void(*f)(char s[]), char s[])
{
	(*f)(s);
}

int main()
{
	char str[10];
	int n;
	cin >> str;
	cin >> n;
	if (n == 1)
	{
		cipher(caesa, str);
	}
	if (n==2)
	{
		cipher(oddeven, str);
	}
	cout << str << endl;
}