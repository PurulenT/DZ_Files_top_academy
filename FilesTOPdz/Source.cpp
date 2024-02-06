#include <iostream>
#include "struct.h"
#include "enum.h"
#include <string>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Tovar tovarArr[5];
	tovarArr[0] = {"������", 9.99, Category::fructs};
	tovarArr[1] = {"���", 5.99, Category::vegetables};
	tovarArr[2] = {"���", 19.99, Category::milk};
	tovarArr[3] = { "�����", 3.99, Category::sweets };
	tovarArr[4] = {"�������", 5.99, Category::milk};

	bool start = true;
	char quit;
	int count = 0;

	ofstream file("C:\\Users\\nurih\\Desktop\\C++\\���������� �������\\FilesTOPdz\\textovy.txt"); // change if needed
	if (file.is_open())
	{
		while (start)
		{
			file << count + 1 << ". ";
			file << tovarArr[count].name << ",";
			file << tovarArr[count].price << "�, ";
			switch (tovarArr[count].category)
			{
			case Category::fructs:
				file << "������" << endl;
				break;
			case Category::milk:
				file << "�������� ���������" << endl;
				break;
			case Category::vegetables:
				file << "�����" << endl;
				break;
			case Category::sweets:
				file << "��������" << endl;
				break;
			default:
				file << "�� �������" << endl;
				break;
			}

		
			if (count == 4) 
			{
				cout << "��� ������ ���� ������� � ����! ���������� ���������.";
				start = false;
				break;
			}

			count++;

			cout << "���� ��������. ���������� ����? y/n" << endl;
			cin >> quit;
			if (quit == 'y')
				continue;
			else if (quit == 'n')
			{
				cout << "���������� ���������";
				break;
			}
			else
			{
				cout << "������� �������� ��������! ���������� ���������";
				break;
			}
		}
	}

	return 0;
}