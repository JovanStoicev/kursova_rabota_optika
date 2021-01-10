#include "Orderer.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

Orderer::Orderer(string aFirstName, string aLastName, string aCity, string aAddress,
	string aPhone) {
	firstName = aFirstName;
	lastName = aLastName;
	city = aCity;
	address = aAddress;
	phone = aPhone;
}

Orderer::Orderer() {

}

void Orderer::setFirstName(string aFirstName) {
	firstName = aFirstName;
}
string Orderer::getFirstName() {
	return firstName;
}

void Orderer::setLastName(string aLastName) {
	lastName = aLastName;
}
string Orderer::getLastName() {
	return lastName;
}

void Orderer::setCity(string aCity) {
	city = aCity;
}
string Orderer::getCity() {
	return city;
}

void Orderer::setAddress(string aAddress) {
	address = aAddress;
}
string Orderer::getAddress() {
	return address;
}

void Orderer::setPhone(string aPhone) {
	phone = aPhone;
}
string Orderer::getPhone() {
	return phone;
}
istream& operator >> (istream& inorderer, Orderer& obj) {
	inorderer >> obj.firstName;
	inorderer >> obj.lastName;
	inorderer >> obj.city;
	inorderer >> obj.address;
	inorderer >> obj.phone;
	return inorderer;
}
ostream& operator <<(ostream& outorderer, const Orderer& obj) {

	outorderer << obj.firstName << "\n" << obj.lastName << "\n" << obj.city
		<< "\n" << obj.address << "\n" << obj.phone << endl;
	return outorderer;
}