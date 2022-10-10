#include "Header.h"

void LogoBoss()
{
	cout << ""
		<< "\t\t   $$$$$      $$       $$$$$\n"
		<< "\t\t    $$  $$  $$  $$   $$  $$\n"
		<< "\t\t     $$   $$      $$    $$ \n"
		<< "\t\t      $$               $$  \n"
		<< "\t\t       $$$$$$$$$$$$$$$$$   \n";
	for (size_t i = 0; i < 94; i++)
		cout << '_';
	cout << endl;
}

size_t GetDataInt()
{
	while (true)
	{
		size_t num;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\x1b[31mВводи числа, горилла!\x1b[0m\n";
		}
		else
		{
			cin.ignore(32767, '\n');
			return num;
		}
	}
}


void PrintMap(map<size_t, Student> Students)
{
	cout << endl;
	map<size_t, Student>::iterator it = Students.begin();
	fstream fin;
	fin.open("data.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!\n";
		cout << "Создать файл для записи? (да/нет) ";
		string reply;
		getline(cin, reply);
		if (reply == "да" || reply == "Да")
		{
			ofstream("data.txt");
			cout << "Файл успешно создан!\n";
		}
		else
			exit(1);
	}

	for (size_t i = 0; it != Students.end(); ++it, ++i)
	{
		fin << "////////////////////////////////////////////////////////////\n";
		fin << "Студент №" << it->first << endl;
		fin << "Ученик: " << it->second.name << endl;
		fin << "Возраст: " << it->second.age << endl;
		fin << "Группа: " << it->second.group << endl;
		fin << "-----------Оценки:----------------\n";
		map<string, mark>::iterator it2 = it->second.advancment.begin();
		fin << "      Предмет" << setw(21) << "Оценка\n";
		for (; it2 != it->second.advancment.end(); ++it2)
		{
			fin << setw(3) << it2->first;

			if (it2->first.length() != 18)
				fin << setw(30 - it2->first.length()) << it2->second << endl;
			else
				fin << setw(12) << it2->second << endl;
		}
	}
	cout << endl;
}

bool Question()
{
	cout << "Хотите добавить кого-то ещё?: (1/0) ";
	bool next;
	cin >> next;
	return next;
}

void DataBase()
{
	map<size_t, Student> Students;
	string subjects[] = { "Мат.анализу", "Линейной алгебре", "Иностранному языку", "Информатике" };
	bool next = true;
	size_t k = 1;
	while (next)
	{
		Student man;
		cout << "Введите имя ученика: ";
		getline(cin, man.name);

		cout << "Введите возраст ученика: ";
		man.age = GetDataInt();
		//cin.ignore();

		cout << "Введите группу ученика: ";
		getline(cin, man.group);

		for (size_t i = 0; i < 4; i++)
		{
			int num;
			cout << "Введите оценку ученика по ";
			cout << subjects[i] << ": ";
			cin >> num;

			if (num == 5)
				man.advancment.insert(make_pair(subjects[i], exellent));
			else if (num == 4)
				man.advancment.insert(make_pair(subjects[i], good));
			else if (num == 3)
				man.advancment.insert(make_pair(subjects[i], satisfactory));
			else
				man.advancment.insert(make_pair(subjects[i], unsatisfactory));
		}
		Students.insert(make_pair(k, man));
		++k;

		next = Question();
		cin.ignore();
	}

	PrintMap(Students);
}
