#pragma once
#include <string>
#include <stdio.h>
using namespace std;

class Orderer
{
private:
	string firstName;
	string lastName;
	string city;
	string address;
	string phone;
public:
	Orderer(string aFirstName, string aLastName, string aCity, string aAddress,
		string aPhone);
	Orderer();

	void setFirstName(string aFirstName);
	string getFirstName();

	void setLastName(string aLastName);
	string getLastName();

	void setCity(string aCity);
	string getCity();

	void setAddress(string aAddress);
	string getAddress();

	void setPhone(string aPhone);
	string getPhone();

	friend istream& operator >> (istream& inorderer, Orderer& obj);
	friend ostream& operator <<(ostream& outorderer, const Orderer& obj);
};

