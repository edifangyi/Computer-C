#include <iostream>
using namespace std;
char max_(char x,char y){return x>y?x:y;}
int max_(int x,int y){return x>y?x:y;}
float max_(float x, float y){return x>y?x:y;}
void main()
{
	float a=3.14,b=2.718;
	cout<<"d与s："<<max_('d','s')<<"大"<<endl;
	cout<<"24与168"<<max_(28,168)<<"大"<<endl;
	cout<<"3.14与2.718:"<<max_(a,b)<<"大"<<endl;
}