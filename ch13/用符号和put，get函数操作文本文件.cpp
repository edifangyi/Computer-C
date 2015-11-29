/*****************************************************
用符号<<和put函数向文本文件写入一些文字
*****************************************************/
#include<iostream>
#include <fstream>
using namespace std;


int main()
{
	//打开文件
	ofstream out("file.txt");
	if (!out)
	{
		out << "打开文件失败！" << endl;
		return 1;
	}
	//写文件
	out << "Welcome to ";
	char ch[] = "Xi'an Jiaotong University.";
	int i = 0;
	while (ch[i] != 0)//真正编程时只要用一条语句 out<<ch即可
	{
		out.put(ch[i]);
		i++;
	}
	out.close();//关闭文件
	

/*****************************************************
用符号>>和get函数读取文本文件
*****************************************************/
	//打开文件
	ifstream in("file.txt");
	if (!in)
	{
		cout << "不可以打开文件" << endl;
		return 1;
	}
	//读文件
	char ch1[80];
	in >> ch1;	//读取第一个单词Welcome
	cout << ch1;
	in >> ch1;	//读取第二个单词to
	cout << ch1;
	while (in)	//剩余部分用get函数读出并显示
	{
		char c = in.get();//运行结果Welcometo(in>>ch 方式没有空格，后面有空格是因为用的是get) Xi'an Jiaotong University.
		if(in)
			cout << c;
	}
	in.close();//关闭文件

	system("pause");
	return 0;
}