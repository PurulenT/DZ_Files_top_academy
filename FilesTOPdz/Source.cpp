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
	tovarArr[0] = {"Яблоки", 9.99, Category::fructs};
	tovarArr[1] = {"Лук", 5.99, Category::vegetables};
	tovarArr[2] = {"Сыр", 19.99, Category::milk};
	tovarArr[3] = { "Халва", 3.99, Category::sweets };
	tovarArr[4] = {"Сметана", 5.99, Category::milk};

	bool start = true;
	char quit;
	int count = 0;

	ofstream file("C:\\Users\\nurih\\Desktop\\C++\\тренировка удалить\\FilesTOPdz\\textovy.txt"); // change if needed
	if (file.is_open())
	{
		while (start)
		{
			file << count + 1 << ". ";
			file << tovarArr[count].name << ",";
			file << tovarArr[count].price << "р, ";
			switch (tovarArr[count].category)
			{
			case Category::fructs:
				file << "фрукты" << endl;
				break;
			case Category::milk:
				file << "молочная продукция" << endl;
				break;
			case Category::vegetables:
				file << "овощи" << endl;
				break;
			case Category::sweets:
				file << "сладости" << endl;
				break;
			default:
				file << "не указано" << endl;
				break;
			}

		
			if (count == 4) 
			{
				cout << "Все данные были введены в файл! Завершение программы.";
				start = false;
				break;
			}

			count++;

			cout << "Файл обновлен. Продолжить ввод? y/n" << endl;
			cin >> quit;
			if (quit == 'y')
				continue;
			else if (quit == 'n')
			{
				cout << "Завершение программы";
				break;
			}
			else
			{
				cout << "Введено неверное значение! Завершение программы";
				break;
			}
		}
	}

	return 0;
}