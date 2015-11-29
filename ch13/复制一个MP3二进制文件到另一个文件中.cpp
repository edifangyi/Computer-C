/****************************************************************************
假设已经存在一个文本文件“words.txt”，其中为多个单词，个单词之间以空格分隔；
打开这个文件，搜索全部单词；
获取哥个单词、个数以及单词总数量并显示出来。

算法分析：
①输入原始文件和目标文件名；
②分别按照读方式打开原始文件，按照写方式打开目标文件
③循环每次读取原始文件256字节，如果文件结尾则转⑤
④将实际读取的字节写入目标文件中，转③
⑤关闭原始文件和目标文件

二进制文件打开方式为：ios::binary
ofstream fout(szDestFile,ios::binary);//写打开
ifstream fin(szOrigFile,ios::binary);//读打开
定位文件开始：fin.seekg(0L,ios::beg);
读文件内容：fin.read(szBuf,sizeof(char)*256);
实际读文件的内容长度：int length = fin.gcount();
写文件内容：fout.write(szBuf,length);
读写文件过程中错误判断：if(fout.bad());
文件结尾判断：while(!fin.eof());
关闭文件对象：fout.close();关闭目标文件
			fin.close();关闭原始文件
****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

bool mp3cpy(const char *szDestFile, const char * szOrigFile);
int main()
{
	char szOrigFile[50];	//原始文件名
	char szDestFile[50];	//目标文件名
	cout << "请输入原始文件名和目标文件名：";
	cin >> szOrigFile;
	cin >> szDestFile;

	bool bRet = mp3cpy(szDestFile, szOrigFile);
	if (bRet)
	{
		cout << "文件复制成功！" << endl;
	}
	else {
		cout << "文件复制成功！" << endl;
	}
	//system("pause");
	return 1;
}

bool mp3cpy(const char *szDestFile, const char * szOrigFile)
{
	ofstream fout(szDestFile, ios::binary);//以二进制方式打开目标文件
	ifstream fin(szOrigFile, ios::binary);//以二进制方式打开原始文件
	bool bRet = true;
	if (fin.bad()) {//原始文件出错
		bRet = false;
	}
	else {
		fin.seekg(0L, ios::beg);//定位原始文件开始处
		while (!fin.eof()){		//原始文件结尾
			char szBuf[256] = { 0 };
			fin.read(szBuf, sizeof(char) * 256);//每次读取原始文件最多256字节
			int length = fin.gcount();//实际读取的字节数
			if (fout.bad()) {			//目标文件出错
				bRet = false;
				break;
			}
			fout.write(szBuf, length);	//每次写入目标文件length个字节
		}
	}
	fout.close();
	fin.close();
	return bRet;
}