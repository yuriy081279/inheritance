#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define delimiter "\n------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS	const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETER	last_name, first_name, age

class Human
{
	static const int FULL_NAME_LENGTH = 20;
	static const int AGE_LENGTH = 5;
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

	//				Constructors:
	Human(HUMAN_TAKE_PARAMETERS) :
		last_name(last_name), first_name(first_name), age(age)
	{
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	virtual std::ostream& print(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " y.o.";
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		//ofs << last_name << " " << first_name << " " << age;
		ofs.width(FULL_NAME_LENGTH);
		ofs << std::left;
		ofs << last_name + " " + first_name;
		ofs.width(AGE_LENGTH);
		ofs << std::right;
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs);
}

std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}
#define STUDENT_TAKE_PARAMETERS	const std::string& specialty, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS	specialty, group, rating, attendance

class Student :public Human
{
	static const int SPECIALTY_LENGTH=25;
	static const int GROUP_LENGTH=10;
	static const int RATING_LENGTH=8;
	static const int ATTENDANCE_LENGTH=8;
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

	//					Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETER)
	{
		this->specialty = specialty;
		this->group = group;
		this->rating = rating;
		this->attendance = attendance;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//					Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << ", " << specialty << " " << group << " " << rating << " " << attendance;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Human::print(ofs) << " ";
		ofs.width(SPECIALTY_LENGTH);
		ofs << std::left;
		ofs << specialty;
		ofs.width(GROUP_LENGTH);
		ofs << group;
		ofs.width(RATING_LENGTH);
		ofs << std::right;
		ofs << rating;
		ofs.width(ATTENDANCE_LENGTH);
		ofs << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Human::scan(ifs);
		const int SIZE = 25;
		char buffer[SIZE]{};
		ifs.read(buffer, SIZE-1);
		for (int i = SIZE - 2; buffer[i] == ' '; i--)buffer[i] = 0;
		while (buffer[0] == ' ')
		{
			for (int i = 0; buffer[i]; i++)buffer[i] = buffer[i + 1];

		}
		
		specialty = buffer;
		ifs >> group;
		ifs >> rating;
		ifs >> attendance;
		return ifs;
	}
};

class Teacher :public Human
{
	static const int SPECIALTY_LENGTH = 25;
	static const int EXPERIENCE_LENGTH = 5;
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

	//				Constructors:
	Teacher(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& specialty, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//				Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return  Human::print(os) << ", " << specialty << " " << experience;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Human::print(ofs) << " ";
		ofs.width(SPECIALTY_LENGTH);
		ofs << std::left;
		ofs << specialty;
		ofs.width(EXPERIENCE_LENGTH);
		ofs << right;
		ofs << experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Human::scan(ifs);
		const int SIZE = 25;
		char buffer[SIZE]{};
		ifs.read(buffer, SIZE);
		for (int i = SIZE - 2; buffer[i] == ' '; i--)
		{
			buffer[i] = 0;
		}
		while (buffer[0] == ' ')
		{
			for (int i = 0; buffer[i]; i++)
			{
				buffer[i] = buffer[i + 1];
			}
		}
		specialty = buffer;
		ifs >> experience;
		return ifs;
	}
};

class Undergrad :public Student
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
	//				Constructors:
	Undergrad(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& topic) :
		Student(HUMAN_GIVE_PARAMETER, STUDENT_GIVE_PARAMETERS)
	{
		set_topic(topic);
		cout << "GConstructor:\t" << this << endl;
	}
	~Undergrad()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//				Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Student::print(os) << ", Тема дипломного проекта: " << topic;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Student::print(ofs) << " " << topic;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs) override
	{
		Student::scan(ifs);
		std::getline(ifs, topic);
		return ifs;
	}
};


Human* HumanFactory(const std::string& type)
{
	if (type.find("Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Teacher") != std::string::npos)return new Teacher("", "", 0, "",0);
	if (type.find("Undergrad") != std::string::npos)return new Undergrad("", "", 0, "", "", 0, 0, "");

}
void print(Human* group[], const int n)
{
	//Specialisation - Óòî÷íåíèå (DownCast - ïðåîáðàçîâàíèå ñâåðõó âíèç)
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}
}
void save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		fout.width(15);
		fout << std::left;
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();
	std::string command = "notepad " + filename;
	system(command.c_str());
}
Human** load(const std::string& filename, int& n)
{
	std::ifstream fin(filename);
	//1) Âû÷èñëÿåì ðàçìåð ìàññèâà:
	if (fin.is_open())
	{
		std::string buffer;
		for (n = 0; !fin.eof(); n++)
		{
			std::getline(fin, buffer);
		}
		n--;
	}
	//2) Âûäåëÿåì ïàìÿòü ïîä ìàññèâ:
	Human** group = new Human * [n] {};

	//3) Âîçâðàùàåìñÿ â íà÷àëî ôàéëà, äëÿ òîãî ÷òîáû ïðî÷èòàòü ñòðîêè, è çàãðóçèòü èõ â îáúåêòû
	fin.clear();
	fin.seekg(0);
	//cout << fin.tellg() << endl;

	//4) Çàãðóæàåì îáúåêòû èç ôàéëà:

	if (fin.is_open())
	{
		std::string type;
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, type, ':');
			//cout << buffer << endl;
			group[i] = HumanFactory(type);
			fin >> *group[i];
		}
	}
	return group;
}

//#define INHERITANCE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Montana", "Antoio", 25);
	human.print();
	cout << delimiter << endl;

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 95);
	stud.print();
	cout << delimiter << endl;

	Teacher professor("White", "Walter", 50, "Chemistry", 20);
	professor.print();

	Undergrad hank("Schreder", "Hank", 40, "Criminalistic", "WW_220", 95, 80, "How to catch Heisenberg");
	hank.print();
#endif // INHERITANCE

	//Polymorphism (Ìíîãîôîðìåííîñòü) - ýòî ñïîñîáíîñòü îáúåêòîâ âåñòè ñåáÿ ïî ðàçíîìó â çàâèñèìîñòè îò îáñòîÿòåëüñòâ.
	//Ad-hoc polymorphism

	//Runtime polymorphism
	/*
		1. Pointers to base class - ïîçâîëÿþò õðàíèòü àäðåñà äî÷åðíèõ îáúåêòîâ;
			Generalisation - Îáîáùåíèå;
		2. Virtual methods;
	*/

	//Generalisation (UpCast - ïðåîáðàçîâàíèå òèïîâ ñíèçó ââåðõ)
	/*Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 90, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Undergrad("Schreder", "Hank", 40, "Criminalistic", "WW_220", 95, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Criminalistic", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 15),
		new Teacher("Einstein", "Albert", 143, "Astronomy", 120)
	};*/

	//Specialisation - Óòî÷íåíèå (DownCast - ïðåîáðàçîâàíèå ñâåðõó âíèç)
	/*for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}*/

	//print(group, sizeof(group) / sizeof(group[0]));
	//save(group, sizeof(group) / sizeof(group[0]), "group.txt");

	int n = 0;
	Human** group = load("group.txt", n);
	print(group, n);
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}