/*******************从U盘到MP3的设计****************
先设计一个U盘类UDISK
由它派生出MP3类MP3
U盘类只具有储存数据的功能
	即包括按行储存信息的指针数组crow、储存行数nrow
	构造函数、析构函数
	按行读信息函数read、按行写信息函数write
MP3类新增播放音乐函数play、构造函数与析构函数
要求模拟U盘的读写操作以及MP3的播放功能
*******************从U盘到MP3的设计***************/
#include "iostream"
#include "windows.h"
#include "mmsystem.h"
using namespace std;


/*******************************U盘类的定义*******************************/
class UDISK
{
private:
	char *crow[100];
	int nrow;
public:
	UDISK(void) { nrow = 0; }
	void read(void);
	void write(char *pstr);
	~UDISK() { cout << "撤销U盘对象" << endl; }
};
void UDISK::read(void)	//读信息
{
	for (int i = 0;i < nrow;i++)
		cout << crow[i] << endl;
}
void UDISK::write(char *pstr)	//写信息
{
	crow[nrow] = pstr;
	nrow++;
}


/***************************派生MP3类的定义****************************/
class MP3 :public UDISK
{
public:
	MP3() :UDISK() {};
	void play(char *pstr);	//播放
	~MP3() 
	{
		cout << "撤销MP3对象" << endl;
	}
};
void MP3::play(char *pstr)
{
	char str[100] = "play";		//play后有空格
	strcat_s(str, pstr);
	cout << str;
	mciSendStringA(str, NULL, 0, NULL);	//播放函数
}

int main()
{
	UDISK U1;
	cout << "--模拟U盘写--" << endl;
	U1.write("劝学");
	U1.write("hahahahaha");
	U1.write("xixixixixi");
	U1.write("papapapapa");
	U1.write("hehehehehe");

	cout << "--模拟U盘读--" << endl;
	U1.read();
	MP3 M1;
	cout << "--模拟MP3盘读--" << endl;
	//MP3文件与可执行文件放在同一路径中
	M1.play("c:\\邓丽君——甜蜜蜜.mp3");
	char a;
	cin >> a;	//输入任一字符，终止音乐播放
	system("pause");
	return 0;
}