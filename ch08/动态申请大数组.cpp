/********************************************************
本题要求编写两个函数并测试。
第一个函数原型为 int *new_array(int n); 该函数可以根据参数n动态申请n个元素的整型数组，最后将数组指针返回。
第二个函数原型为 void init_array(int *p, int n,int c); 将指定的n个元素的数组每个元素的值均初始化为c。

用户输入数组大小n和待初始化的值c,调用new_array函数申请空间，再调用init_array初始化，最后输出这个数组的所有元素。

输入格式:
数组大小n和待初始化的值c

输出格式：
数组的所有元素,注意最后一个元素后没有空格

输入样例：
8 27

输出样例：
27 27 27 27 27 27 27 27
*********************************************************/
#include <iostream>
using namespace std;
int *new_array(int n)
{
    return new int[n];
}
void init_array(int *p,int n,int c)
{
    for(int i=0;i<n;*(p+i++)=c)
		;
}
int main()
{
    int n,c,*p;
    cin >> n >> c;
    p=new_array(n);
    init_array(p,n,c);
    for(int i=0;i<n;i++)
	{	if(i==0)
       cout << *(p+i);
		else 
		cout <<" "<< *(p+i);
	}
    return 0;
}