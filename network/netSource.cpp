#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	char number[10] = {};
	char src_filename[_MAX_FNAME] = {};	//_MAX_FNAME - ��� ��������� ���������, ������� �������� ����������� ��������� ����� ����� �����
	char wal_filename[_MAX_FNAME] = {};
	char dhcpd_filename[_MAX_FNAME] = {};
	//src (source) - ���� ��������, �� �������� ���������� ������� MAC � IP ������
	//dst (destination) - ��� �������� ����, � ������� �������� ����� �������� �������

	cout << "������� ����� ���������: "; cin >> number;
	//�� ���������� ������ ��������� ��������� ����� ������, ��� ���������, ��� � ���������:
	strcat(src_filename, number);
	strcat(src_filename, " RAW.txt");
	//strcat(dst, src);	//���������� ������ src ��������� � ����� ������ dst
	//strcat - ��������� ������������ �����, � ������,
	//� ������ ������ (filename) ��������� ������ ������ (" RAW.txt");
	strcat(wal_filename, number);
	strcat(wal_filename, " ready.txt");

	strcat(dhcpd_filename, number);
	strcat(dhcpd_filename, " .dhcpd");

	const int IP_SIZE = 16;
	const int MAC_SIZE = 18;

	char sz_ip_buffer[IP_SIZE] = {};
	char sz_mac_buffer[MAC_SIZE] = {};

	ofstream fout(wal_filename);
	ifstream fin(src_filename);

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t\t" << sz_ip_buffer << endl;
			fout << sz_mac_buffer << "\t\t" << sz_ip_buffer << endl;
		}
		//fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	fout.close();
	char sz_command[_MAX_FNAME] = "notepad ";
	strcat(sz_command, wal_filename);
	system(sz_command);

	fin.clear();
	fin.seekg(0);
	cout << fin.tellg() << endl;
}