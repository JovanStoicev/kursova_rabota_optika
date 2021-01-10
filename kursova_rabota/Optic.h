#pragma once
#include <string>
#include <stdio.h>

using namespace std;

class Optic
{
private:
	float widht = 0;
	float dioptre = 0;
	float price = 0;

	string type;
	string material;

public:
	Optic(float aWidht, float aDioptre, string aType, string aMaterial, float aPrice);

	Optic();

	void setWidht(float aWidht);
	float getWidht();

	void setDioptre(float aDioptre);
	float getDioptre();

	void setType(string aType);
	string getType();

	void setMaterial(string aMaterial);
	string getMaterial();

	void setPrice(float aPrice);
	float getPrice();

	friend istream& operator >> (istream& inoptic, Optic& obj);
	friend ostream& operator <<(ostream& outoptic, const Optic& obj);
};

