/********************************************************题目内容：
用户首先输入两个整数m和n,然后输入m*n个元素，建立一个m*n的二维数组。要求使用 行指针 来遍历这个二维数组，输出该数组中所有元素的和。

输入格式:
首先输入两个整数m和n,然后依次输入m*n个元素

输出格式：
二维数组中所有元素的和

输入样例：
2 3
1 3 5 
2 4 6

输出样例：
21
*********************************************************/
#include<iostream>
#include<cstring>
#include<cmath>
#include <iomanip>
using namespace std;
int main()
{
	int m, n;
	int sum = 0;
	cin >> m >> n;
	int k = 1;
	//动态开辟空间
	int **a = (int **)new int*[m];//开辟行
	for (int i = 0;i < m;i++) //开辟列
		a[i] = new int[n];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += a[i][j];
		}
	}

	cout << sum;
}