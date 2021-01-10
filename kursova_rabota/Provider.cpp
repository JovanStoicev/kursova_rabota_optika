#include <string>
#include <stdio.h>
#include <iostream>
#include "Provider.h"
using namespace std;


Provider::Provider(string ime, string broj, string bulstatBroj, string lokacija) {
		name = ime;
		number = broj;
		bulstat = bulstatBroj;
		location = lokacija;
}

Provider::Provider() {};

void Provider::setName(string aName) {
	name = aName;
}
string Provider::getName() {
	return name;
}

void Provider::setNumber(string aNumber) {
	number = aNumber;
}
string Provider::getNumber() {
	return number;
}
void Provider::setBulstat(string aBulstat) {
	bulstat = aBulstat;
}
string Provider::getBulstat() {
	return bulstat;
}

void Provider::setLocation(string aLocation) {
	location = aLocation;
}
string Provider::getLocation() {
	return location;
}

istream& operator >> (istream& inprovider, Provider& obj)
{
	inprovider >> obj.name;
	inprovider >> obj.number;
	inprovider >> obj.bulstat;
	inprovider >> obj.location;
	return inprovider;
}
ostream& operator<<(ostream& outprovider, const Provider& obj)
{
	outprovider << obj.name << "\n" << obj.number << "\n" << obj.bulstat
		<< "\n" << obj.location << endl;
	return outprovider;
}


