#include "Date.h"

Date::Date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Date::Date(int _day, int _month, int _year)
{
	this->day = _day;
	this->month = _month;
	this->year = _year;
}

Date::Date(string _date)
{
	this->day = stoi(_date.substr(0, 2));
	this->month = stoi(_date.substr(3, 2));
	this->year = stoi(_date.substr(6, 4));
}

void Date::read(string s_date) {

	this->day = stoi(s_date.substr(0, 2));
	this->month = stoi(s_date.substr(3, 2));
	this->year = stoi(s_date.substr(6, 4));
};

void Date::print(ostream& os) const
{
	//os << day << '.' << month << '.' << year;
	os << (day < 10 ? "0" : "") << day << "."
		<< (month < 10 ? "0" : "") << month << "."
		<< year;
}


