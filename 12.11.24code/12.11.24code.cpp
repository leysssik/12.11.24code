#include<iostream>
#include <string>
#include <fstream>
#include<vector>
#include<algorithm>
#include <iomanip>
#include <sstream>
using namespace std;
struct Student
{
	int id{};
	string f{};
	string i{};
	string o{};
	char pol{};
	int age{};
	double rost{};
	int predm[4]{};
};
int Stroka(string s)
{
	int NumL = 0;
	string stroka;
	ifstream fin;
	fin.open(s);
	while (getline(fin, stroka))
	{
			if(!stroka.empty())
			{NumL++;}
	}
	return NumL;
}
int Probeli(string s)
{
	int NumL = 0;
	ifstream fin;
	fin.open(s);
	while (!fin.eof())
	{
		char ch;
		fin.get(ch);
		if (ch == ' ')
		{
			NumL++;
		}
	}
	return NumL;
}
int main()
{
	ofstream fout;
	ifstream fin;
	fin.open("student.txt");
	int a = Stroka("student.txt");
	cout << a << endl;
	int b = Probeli("student.txt");
	cout << b << endl;
	int c = a + b;
	vector<string>student;
	for(size_t i =0; i<c; i++)
	{
		string str;
		fin >> str;
		student.push_back(str);
	}
	fin.close();
	int Column = 10;
	vector<int>Temp_vozr;
	for (size_t i = Column-6; i < student.size(); i=i+=Column)
	{
		if (student[i]!="0")
		{
			Temp_vozr.push_back(stoi(student[i].c_str()));
		}
	}
	vector<int>vozr;
	Temp_vozr.swap(vozr);
	float SUMMA = 0;
	for (size_t i = 0; i < vozr.size(); i++)
	{
		SUMMA += vozr[i];
	}
	cout << SUMMA / a << endl;
}
