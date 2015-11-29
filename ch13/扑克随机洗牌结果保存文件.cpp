/*****************************************************
首先由程序生生成初始的52张扑克牌；
然后通过随机交换达到洗牌的目的，并将洗牌结果分发给四个牌手各13张；
最后将系怕结果保存到一个文本文件中。
*****************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SUIT_NUMBER 4
#define  FACE_NUMBER 13
class Card
{
public:
	string suit;	//花色
	string face;	//面值
};

class CardManager
{
private:
	Card deck[SUIT_NUMBER][FACE_NUMBER];//4*13=52张扑克牌
public:
	CardManager() {//构造函数
		string suit[] = { "红桃","方块","梅花","黑桃" };
		string face[] = 
		{ "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
		for (int i = 0; i < SUIT_NUMBER; i++){
			for (int j = 0; j < FACE_NUMBER; j++){
				deck[i][j].suit = suit[i];
				deck[i][j].face = face[j];
			}
		}
	}	
	void shuffle() {//洗牌
		srand(time(NULL));
		for (int i = 0; i < SUIT_NUMBER; i++) {
			for (int j = 0; j < FACE_NUMBER; j++) {
				int m = rand() % SUIT_NUMBER;
				int k = rand() % FACE_NUMBER;
				Card temp = deck[i][j];
				deck[i][j] = deck[m][k];
				deck[m][k] = temp;
			}
		}
	}
	void deal() 
	{//发牌
		ofstream out("puke.txt");//打开文件
		if (!out) {//判断文件是否正确打开
			cout << "文件打开失败！" << endl;
			return;
		}
		out << "===============" << endl;
		out << " 52张牌洗牌结果 " << endl;
		out << "===============" << endl;
		string person[] = { "甲","乙","丙","丁" };
		for (int i = 0;i < SUIT_NUMBER; i++) {
			out << person[i] << "的牌" << endl;
			for (int j = 0; j < FACE_NUMBER; j++) {
				out << "第" << j + 1 << "张： " << deck[i][j].suit << deck[i][j].face << "\t\t";
				if ((j + 1) % 4 == 0) {
					out << endl;
				}
			}
			out << endl << endl;
		}
		out.close();
		cout << "puck.txt文件成功生成，请查阅！" << endl;
	}	
};


int main()
{
	CardManager cm;//建立对象
	//打开文件
	cm.shuffle();//洗牌
	cm.deal();//发牌

	//system("pause");
	return 1;
}