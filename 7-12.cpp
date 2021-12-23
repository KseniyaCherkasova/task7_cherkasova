#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;
int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str, str2;
	int max, k, len;
	char h;

	do
	{
		h = ' ';
		len = 0;
		max = 0;
		str = "\0";
		cout << str;

		cout << "Считать с файла или ввести вручную? 1 или 2: "; cin >> k;

		if (k == 1)
		{
			ifstream str_file("stroka.txt");
			if (!str_file.is_open())
			{
				cout << "Файл не открылся! Выход... ";
				return 0;
			}

			while (!str_file.eof())
			{
				str_file.get(h);
				str += h;
			}

			cout << "Строка из файла: " << str << endl;
			str_file.close();
		}
		else { 
			getline(cin, str2); 

			while (str.size() == 0)
			{
				getline(cin, str); 
				if (str.size() == 0)
				{
					cout << "Необходимо ввести 1 или более символов: " << endl;
				}
			}


		}

		str[str.size()] = ' ';

		for (int i = 0; i <= str.size(); i++) // АЛГОРИТМ ДЛЯ ПОДСЧЁТА МАКСИМАЛЬНОЙ ДЛИННЫ 
		{
			if (str[i] != ' ')
			{
				len++;
			}
			else if (len > max)
			{
				max = len;
				len = 0;
			}
			else {
				len = 0;
			}
		}

		cout << "\nСамые длинные слова: ";
		for (int i = 0; i <= str.size(); i++)
		{
			if (str[i] != ' ')
			{
				len++;
			}
			else if (len == max)
			{
				for (int j = i - len; j < i; j++)
				{
					cout << str[j];
				}
				cout << ' ';
				len = 0;
			}
			else
			{
				len = 0;
			}
		}

		cout << "  (Их длинна: " << max << ')';


		cout << "\n-----------------------------------------------------------";
		cout << "\nЕщё раз? (Ввести у - да, n - нет) "; cin >> h;
	} while (h != 'n');
}

