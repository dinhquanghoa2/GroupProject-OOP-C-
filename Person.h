#include<iostream>
using namespace std;
#include"Date.h"
#include"Address.h"
#pragma once
#ifndef PERSON_H
#define PERSON_H
class Person
{
protected:
	string idNumber;
	string name;
	string phoneNumber;
	string sex;
	Date dob;
	Address adress;
public:
	Person();
	Person(string, string, string, string, Date dob, Address address);
	string getIdNumber();
	string getName();
	string getPhoneNumber();
	string getSex();
	Date getDob();
	Address getAddress();
	void setIdNumber(string idNumber);
	void setName(string name);
	void setPhoneNumber(string phoneNumber);
	void setSex(string sex);
	void setAddress(Address address);
	void setDob(Date dob);
	virtual void input();
	virtual void output();
	friend istream& operator>>(istream& is, Person& person);
	friend ostream& operator<<(ostream& os, Person& person);
	void doc_filePerson(ifstream& filein);
};
#endif
