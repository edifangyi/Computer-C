/*****************************************************
假设一个文件file.txt，内容为学习成绩，每一行的形式为：
姓名/数学成绩/英语成绩/物理成绩。数据中间用空格隔开。
编写程序读取每一行的内容，计算出每人的平均成绩后，
写入输出文件。输出文件名由用户输入，输出文件每一行的
形式为：姓名/数学/英语/物理/平均成绩
新建：file.txt
张三	87	66	89
李四	98	79	77
王五	89	92	89
*****************************************************/
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	char ch[20];
	int math, eng, phy;
	ifstream fin("file.txt");
	ofstream fout("res.txt");
	if (!fin||!fout)
	{
		cout << "不可以打开文件" << endl;
		return 1;
	}
	
	//读文件
	while (fin)
	{
		fin >> ch >> math >> eng >> phy;//一行的信息
		if (fin)
		{
			float avg = 1.0*(math + eng + phy) / 3;
			fout << ch << '\t' << math << '\t' << eng << '\t' << phy << '\t' << avg << endl;
		}
		
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}