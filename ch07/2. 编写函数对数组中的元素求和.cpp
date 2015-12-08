/********************************************************
题目内容：
编写函数 add_array 对数组中的元素求和，函数原型为：
void add_array(int a, int *sum);
该函数可以重复调用多次，每次只使用参数a传入数组中的一个元素，函数内部可以累计历次传入的值进行求和，每次执行后均把当前的和通过参数sum写入主函数中的某个变量中。
提示：使用静态变量。

输入格式:
一个最多100个元素的整型数组，以-1为结尾。

输出格式：
该数组所有元素的和

输入样例：
3 9 27 4 5 -1

输出样例：
4848
*********************************************************/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

void add_array(int a, int *sum);

int main()
{
	int num[100];
	int C = 0, *pta = &C;
	int n = 0;

	for (int i = 0;i < 100;i++)
	{
		cin >> num[i];
		n++;
		if (num[i] == -1)
			break;
		add_array(num[i], pta);
	}

// 	for (int i = 0;i < n-1;i++)
// 	{
// 		add_array(num[i], pta);
// 	}
	cout << *pta << endl;

}

void add_array(int a, int *sum)
{
	((*sum) += a);
}