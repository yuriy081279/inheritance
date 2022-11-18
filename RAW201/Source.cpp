#include<iostream>
#include<fstream>

#define WRITE_TO_FILE 
#define READ_FROM_FILE 
using namespace std;

void main()
{
	const char  RAW = 12;
	const char COLS = 40;
	char arr[RAW][COLS];	

	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE 	
	std::ofstream fout;	
	system("notepad RAW201.txt");
#endif // WRITE_TO_FILE 
	std::ifstream fin("RAW201.txt");
	if (fin.is_open())
	{
		// читаем файл	
		std::ifstream file("RAW201.txt");		
		char x; // Символ при чтении из файла
		if (file.is_open())
		{				
				for (int i = 0; i < RAW; i++)
				{					
					for (int j = 0; j < COLS; j++)
					{
						file.get(x);
						arr[i][j] = x;						
						if (j > 21) 
						{			
							std::swap(arr[i][j - 22], arr[i][j]);		
							std::cout << arr[i][j-22];	
							
							fout.open("FileRAW.txt", std::ios::app);
							fout << arr[i][j - 22];
							fout.close();
							if (j >= 39)
							{
								int d = 17;
								for (int c = 0; c < 18; c++)
								{									
									cout << arr[i][j-d]; 									
									fout.open("FileRAW.txt", std::ios::app);
									fout << arr[i][j-d];
									fout.close();
									--d;
								}
							}
						}							
					}
					fout.open("FileRAW.txt", std::ios::app);					
					fout << endl;
					fout << endl;
					cout << endl;					
					cout << endl;	
					fout.close();
				}								
				system("notepad FileRAW.txt");
				file.close();
		}	
	}
}