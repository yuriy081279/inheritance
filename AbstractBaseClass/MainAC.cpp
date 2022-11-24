#include<iostream>
using namespace std;
//virtual type name (parameters) = 0;

class Animal
{
	std::string name;

public:
	virtual void sound()const=0;

};

class cat :public Animal
{

};

class Tiger :public cat
{
public:
	void sound()const override
	{
		cout << "Rrrrrrrrr" << endl;
	}
};
class Lion :public cat
{
public:
	void sound()const override
	{
		cout << "RRRRRRR" << endl;
	}
};

class dog :public Animal{};
class Wolf :public dog
{
public:
	void sound()const override
	{
		cout << "GAV" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");

	//Animal slon;

	//Cat Tom;
	/*Tiger tig;
	tig.sound();

	Lion leo;
	leo.sound();

	Wolf heart;
	heart.sound();*/

	Animal* zoo[] =
	{
		new Tiger,
		new Lion,
		new Wolf
	};
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}



}