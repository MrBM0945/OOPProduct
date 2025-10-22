#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;

	Date();
	Date(int day, int month, int year);
	Date(string _date);
	void read(string s_date);
	void print(ostream& os) const;
};