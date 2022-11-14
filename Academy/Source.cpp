#include<iostream>
#include<string>
using namespace std;
#define delimetr "\n----------------------------------------------\n"
#define HUMAN_TAKE_PARAMETERS  const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS  last_name,  first_name,  age
#define STUDENT_TAKE_PARAMETERS const std::string& specialty, const std::string group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS specialty, group, rating, attendance

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	/*void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}*/

	
	/// ///////////// CONSTRUCTORS


	Human(HUMAN_TAKE_PARAMETERS):
	last_name(last_name), first_name(first_name), age(age)
	{
		cout << "HConstructor:\t "<< this << endl;
	}
	virtual ~Human()
	{
		cout << "Hdestructor:\t" << this << endl;
	}
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет.\n";
	}
	/*virtual std::ostream& print(std::ostream&)const
	{
		cout << last_name << " " << first_name << " " << age << " лет.\n";
	}*/
}; 

std::ostream& operator<<(std::ostream os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << "  " << obj.get_age() << endl;
}
class Student:public Human
{
	std::string specialty;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	////Constructors
	Student(HUMAN_TAKE_PARAMETERS, 
		STUDENT_TAKE_PARAMETERS):
		Human(HUMAN_GIVE_PARAMETERS)
	{
		this->specialty = specialty;
		this->group = group;
		this->rating = rating;
		this->attendance = attendance;
		cout << "Sconstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "Sdestructor:\t" << this << endl;
	}
	void print() const
	{
		Human::print();
		cout << specialty << "  " << group << "  " << rating << " " << attendance << "  " << endl;
	}
};
class Teacher: public Human
{
	std::string specialty;
	unsigned int experience;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	/////Constructors
	Teacher(HUMAN_TAKE_PARAMETERS,
		const std::string& specialty, unsigned int experience):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "Tconstructor:\t " << this << endl;
	}
	~Teacher()
	{
		cout << "Tdestructor:\t " << this << endl;
	}
	void print() const
	{
		Human::print();
		cout << specialty << "  " << experience << "  " << endl;
	}
};

class GS:public Student
{
	std::string topic;
public:
	const std::string& get_topic()const
	{
		return topic;
	}
	void set_topic(const std::string& topic)
	{
		this->topic = topic;
	}

	GS(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& topic)
	:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_topic(topic);
		cout << "GSconstructor:\t " << this << endl;
	}
	~GS()
	{
		cout << "GSdestructor:\t " << this << endl;
	}

	void print() const
	{
		Student::print();
		cout << topic << "  " << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("Montana", "Antonio", 25);
	human.print();
	cout << delimetr << endl;

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "VV 220", 90, 95);
	stud.print();
	cout << delimetr << endl;

	Teacher professor("Walter", "White", 50, "Chemistry", 15);
	professor.print();
	cout << delimetr << endl;

	GS ktoto("Vasiliy", "Ivanov", 25, "Chemistry", "FF 230", 90, 67, "LSD");
	ktoto.print();

	Human* group[] =
	{
	new Student("Pinkman", "Jessie", 25, "Chemistry", "VV 220", 90, 95),
	new Teacher("Walter", "White", 50, "Chemistry", 15),
	new GS("Vasiliy", "Ivanov", 25, "Chemistry", "FF 230", 90, 67, "LSD"),
	new Student("Pink", "Jes", 25, "Chem", "V 2", 97, 00),
	new Teacher("Wal", "Wh", 50, "Chem", 19),
	new GS("Vas", "Iv", 25, "Chem", "F 23", 9, 6, "LSD")
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
		cout << delimetr << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

}
