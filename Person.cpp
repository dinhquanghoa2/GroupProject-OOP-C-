#include "Person.h"
#include"Date.h"
#include"Address.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
Person::Person() {
	this->idNumber = this->name = this->phoneNumber = this->sex = "";
}
Person::Person(string idNumber, string name, string phoneNumber, string sex, Date dob, Address address) {
	setIdNumber(idNumber);
	setName(name);
	setPhoneNumber(phoneNumber);
	setSex(sex);
	setDob(dob);
	setAddress(address);
}
string Person::getIdNumber() {
	return this->idNumber;
}
string Person::getName() {
	return this->name;
}
string Person::getPhoneNumber() {
	return this->phoneNumber;
}
string Person::getSex() {
	return this->sex;
}
Date Person::getDob() {
	return this->dob;
}
Address Person::getAddress() {
	return this->adress;
}
void Person::setIdNumber(string idNumber) {
	this->idNumber = idNumber;
}
void Person::setName(string name) {
	this->name = name;
}
void Person::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}
void Person::setSex(string sex) {
	this->sex = sex;
}
void Person::setAddress(Address address) {
	this->adress = address;
}
void Person::setDob(Date dob) {
	this->dob = dob;
}
void Person::input() {
	cout << "\tEnter IdNumber:";
	getline(cin, idNumber);
	cout << "\tEnter Name:";
	getline(cin, name);
	cout << "\tEnter PhoneNumber:";
	getline(cin, phoneNumber);
	cout << "\tEnter Sex:";
	getline(cin, sex);
	cout << "\t- Date Of Birth\n";
	cin >> dob;
	cout << "\t- Address\n";
	cin >> adress;
}
istream& operator>>(istream& is, Person& person) {
	person.input();
	return is;
}
void Person::output() {
	cout << "\n\tID:" << idNumber << "   FullName:" << name << "\n\tSex:" << sex << "   Contact:" << phoneNumber;
	cout << "\n\tDate Of Birth:" << dob;
	cout << "\n\t" << adress;
}
ostream& operator<<(ostream& os, Person& person) {
	person.output();
	return os;
}
void Person::doc_filePerson(ifstream& filein) {
	getline(filein, this->idNumber, ',');
	filein.seekg(1, 1);
	getline(filein, this->name, ',');
	filein.seekg(1, 1);
	getline(filein, this->phoneNumber, ',');
	filein.seekg(1, 1);
	getline(filein, this->sex, ',');
	filein.seekg(1, 1);
	dob.doc_fileDate(filein);
	adress.doc_fileAddress(filein);
}