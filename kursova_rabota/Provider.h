#pragma once
#include <string>
#include <stdio.h>

using namespace std;

class Provider
{
private:
	string name,
		number,
		bulstat,
		location;

public:
	Provider(string ime, string broj, string bulstatBroj, string lokacija);
	Provider();

	void setName(string aName);
	string getName();

	void setNumber(string aNumber);
	string getNumber();

	void setBulstat(string aBulstat);
	string getBulstat();

	void setLocation(string aLocation);
	string getLocation();

	friend ostream& operator << (ostream& outprovider, const Provider& obj);
	friend istream& operator >> (istream& inprovider, Provider& obj);
};


