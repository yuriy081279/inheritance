#include<iostream>
#include<fstream>

#define WRITE_TO_FILE 
#define READ_FROM_FILE 

using namespace std;

void main()
{
#ifdef WRITE_TO_FILE 
	setlocale(LC_ALL, "");
	std::ofstream fout;
	fout.open("File.txt", std::ios::app);
	fout << "Hello Files!" << endl;
	fout.close();
	system("notepad File.txt");
#endif // WRITE_TO_FILE 

	ifstream fin("File.txt");
	if (fin.is_open())
	{
		// читаем файл

		const int SIZE = 1024;
		char buffer[SIZE] = {};
		while (!fin.eof())
		{
			//fin >> buffer;
			cout << fin.tellg() << "\t";
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		cout << fin.tellg() << "\n";
		fin.close();
	}
	else
	{
		std::cerr << "   ERROR  " << endl;
	}

	fin.close();

}