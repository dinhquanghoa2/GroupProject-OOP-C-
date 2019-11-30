#include "Date.h"
#include<fstream>
#include<iostream>
using namespace std;
Date::Date() {
	this->day = this->month = 1;
	this->year = 1900;
}
Date::Date(int d, int m, int y) {
	setYear(y);
	setMonth(m);
	setDay(d);
}
int Date::getDay() {
	return this->day;
}
void Date::setDay(int d) {
	if (d<0 || d>maxDay())
		this->day = 1;
	else
		this->day = d;
}
int Date::getMonth() {
	return this->month;
}
void Date::setMonth(int m) {
	if (m < 0 || m>12)
		this->month = 1;
	else
		this->month = m;
}
int Date::getYear() {
	return this->year;
}
void Date::setYear(int y) {
	if (y < 1900 || y>5000)
		this->year = 0;
	else
		this->year = y;
}
void Date::input() {
	cout << "\tEnter year:";
	cin >> year;
	setYear(year);
	cout << "\tEnter month:";
	cin >> month;
	setMonth(month);
	cout << "\tEnter day:";
	cin >> day;
	setDay(day);
	cin.ignore();
}
int Date::getNumberOfDay(Date d) {
	if (d.month < 3) {
		d.year--;
		d.month += 12;
	}
	return 365 * d.year + d.year / 4 - d.year / 100 + d.year / 400 + (153 * d.month - 457) / 5 + d.day - 306;
}

void Date::output() {
	cout << day << "/" << month << "/" << year;
}
istream& operator>>(istream& is, Date& date) {
	date.input();
	return is;
}
ostream& operator<<(ostream& os, Date& date) {
	date.output();
	return os;
}
void Date::doc_fileDate(ifstream& filein) {
	filein >> this->day;
	filein.seekg(1, 1); 
	filein >> this->month;
	filein.seekg(1, 1); 
	filein >> this->year;
	filein.seekg(1, 1);
}