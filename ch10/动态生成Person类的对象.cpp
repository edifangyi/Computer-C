#include <iostream>
#include <string.h>
using namespace std;

class Person
{
private:
	char Name[20];
	int Age;
	char Sex;
public:
	Person();
	void Register(char *name, int age, char sex);
	void ShowMe_1();
	void ShowMe_2();
	Person& operator=(const Person& oths)
	{
		if (&oths == this)
			return *this;
		strcpy_s(Name, oths.Name);
		this->Age = oths.Age;
		this->Sex = oths.Sex;
		return *this;
	}

	~Person() {
		cout << "Now destroying the instance of Person" << endl;
		
	}
};

Person::Person()
{
	strcpy_s(Name, "XXX");
	Age = 0;
	Sex = 'm';
}

void Person::Register(char *name, int age, char sex)
{

	strcpy_s(Name, name);
	Age = age;
	Sex = (sex == 'm' ? 'm' : 'f');
}


void Person::ShowMe_1()
{
	cout << "person1:" << Name << " " << Age << " " << Sex << endl;
}

void Person::ShowMe_2()
{
	cout << "person2:" << Name << " " << Age << " " << Sex << endl;
}


int main()
{
	Person* P1 = new Person();
	Person* P2 = new Person();

	char Name[20];
	int age;
	char sex;

	cin >> Name >> age >> sex;



	P1->ShowMe_1();
	P2->ShowMe_2();


	P1->Register(Name, age, sex);
	*P2 = *P1;
	P1->ShowMe_1();
	P2->ShowMe_2();

	delete P1;
	delete P2;

	system("pause");
	return 0;
}

