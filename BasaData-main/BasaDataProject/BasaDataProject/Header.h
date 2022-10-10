#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

enum mark
{
	unsatisfactory = 2,
	satisfactory,
	good,
	exellent
};

struct Student
{
	string name;
	size_t age;
	string group;
	map<string, mark> advancment; // advancement, править лень
};

void DataBase();
void PrintMap(map<size_t, Student> Students);
bool Question();
void LogoBoss();
size_t GetDataInt();
