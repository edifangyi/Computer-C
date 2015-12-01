/********************************************************
1利用指针输出数组中的元素（20分）
题目内容：
编写程序，把从1到n的n个整数赋予某个int型数组，然后用int型
指针输出该数组元素的值。,

输入格式:
输入参数n

输出格式：
输出是1到n n个数组元素,注意最后一个元素之后没有空格。

输入样例：
9

输出样例：
1 2 3 4 5 6 7 8 9
*********************************************************/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


int main()
{
	int n;
	int j = 1;
	int *num;
	num = new int [1000];
	
	cin >> n;

	num = new int [n];
	for (int i = 0;i < n;i++)
	{
		
		num[i] = j;
		j++;
		if (num[i] == 1)
			cout << num[0];
		else
			cout << " " << num[i];
	}
}