/****************************************************************************
假设已经存在一个文本文件“words.txt”，其中为多个单词，个单词之间以空格分隔；
打开这个文件，搜索全部单词；
获取哥个单词、个数以及单词总数量并显示出来。

算法分析：
①定义存放单词和个数的单词类；
②定义单词类数组；
③打开文件读；
④循环读取一个单词，如果文件结束转⑥；
⑤保存单词个数，并统计单词总数量；
⑥关闭文件对象；
⑦显示个单词和个数以及单词总数量。
****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


class wordtype//单词类
{
public:
	char word[20];//单词
	int count;//数量
};
int getwords(wordtype *words);
int main()
{
	string s;
	wordtype words[100] = { "",0 };//单词对象变量定义与初始化

	int n = getwords(words);//调用获取单词的数量

	cout << "英文单词统计结果如下： " << endl;
	for (int m = 0; m < n; m++)
	{
		cout << words[m].word << ':' << words[m].count << endl;
	}
	cout << "搜索出共" << n << "个单词。" << endl;

	//system("pause");
	return 1;
}

int getwords(wordtype *words) {
	ifstream in("words.txt");
	if (!in){
		cout << "文件打开错误" << endl;
		return 1;
	}

	int n = 0;
	char word[20];
	int m;

	while (in) {
		in >> word;//读单词
		if (!in) {
			break;
		}
		bool flag = false;
		for (m = 0;m < n;m++) {
			if (!strcmp(word, words[m].word)) {//已存在该单词
				words[m].count++;//原有单词计数加1
				flag = true;
				break;
			}		
		}
		if (!flag) {//发现新单词
			words[m].count = 1;//新单词计数为1
			strcpy(words[m].word, word);//保存新单词
			n++;//总单词计数加1
		}
	}		
	in.close();
	return n;
}