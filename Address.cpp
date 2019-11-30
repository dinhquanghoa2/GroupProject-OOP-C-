#include "Address.h"
#include <string>
#include<fstream>
#include<iostream>
using namespace std;
Address::Address() {
	this->numberAddress = this->street = this->district = this->city = this->country = "";
}
Address::Address(string number, string street, string district, string city,string country) {
	setNumberAddress(number);
	setStreet(street);
	setDistrict(district);
	setCity(city);
	setCountry(country);
}
string Address::getNumberAddress() {
	return this->numberAddress;
}
string Address::getStreet() {
	return this->street;
}
string Address::getDistrict() {
	return this->district;
}
string Address::getCity() {
	return this->city;
}
string Address::getCountry() {
	return this->country;
}
void Address::setNumberAddress(string number) {
	this->numberAddress = number;
}
void Address::setStreet(string street) {
	this->street = street;
}
void Address::setDistrict(string district) {
	this->district = district;
}
void Address::setCity(string city) {
	this->city = city;
}
void Address::setCountry(string country) {
	this->country = country;
}
void Address::input() {
	//cin.ignore();
	cout << "\tEnter NumberAddress:";
	getline(cin, numberAddress);
	cout << "\tEnter Street:";
	getline(cin, street);
	cout << "\tEnter District:";
	getline(cin, district);
	cout << "\tEnter City:";
	getline(cin, city);
	cout << "\tEnter Country:";
	getline(cin, country);
}
void Address::output() {
	cout << "Address:" << numberAddress << " - " << street << " - " << district << " - " << city << " - " << country << endl;
}
istream& operator>>(istream& is, Address& add) {
	add.input();
	return is;
}
ostream& operator<<(ostream& os, Address& add) {
	add.output();
	return os;
}
void Address::doc_fileAddress(ifstream& filein) {
	getline(filein, this->numberAddress,'-');
	filein.seekg(1, 1);
	getline(filein, this->street, '-');
	filein.seekg(1, 1);
	getline(filein, this->district, '-');
	filein.seekg(1, 1);
	getline(filein, this->city, '-');
	filein.seekg(1, 1);
	getline(filein, this->country, ',');//doc den ',' thi dung
}