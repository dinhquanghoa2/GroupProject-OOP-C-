#include<iostream>
using namespace std;
#pragma once
#ifndef DATE_H
#define DATE_H
class Date {
protected:
	int day, month, year;
public:
	Date();
	Date(int, int, int);
	int maxDay() {
		if (this->month == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				return 29;
			else
				return 28;
		}
		if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
			return 30;
		else
			return 31;
	}
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getNumberOfDay(Date);
	void input();
	void output();
	friend istream& operator>>(istream& is, Date& date);
	friend ostream& operator<<(ostream& os, Date& date);
	void doc_fileDate(ifstream& filein);
};
#endif
