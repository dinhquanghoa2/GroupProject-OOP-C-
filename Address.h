#include<iostream>
using namespace std;
#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
class Address
{
protected:
	string numberAddress, street, district, city, country;
public:
	Address();
	Address(string, string, string, string, string);
	string getNumberAddress();
	string getStreet();
	string getDistrict();
	string getCity();
	string getCountry();
	void setNumberAddress(string number);
	void setStreet(string street);
	void setDistrict(string district);
	void setCity(string city);
	void setCountry(string country);
	void input();
	void output();
	friend istream& operator>>(istream& is, Address& add);
	friend ostream& operator<<(ostream& os, Address& add);
	void doc_fileAddress(ifstream& filein);
};
#endif
