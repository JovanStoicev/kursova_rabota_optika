#include "Optic.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

Optic::Optic(float aWidht, float aDioptre, string aType, string aMaterial, float aPrice) {
	widht = aWidht;
	dioptre = aDioptre;
	type = aType;
	material = aMaterial;
	price = aPrice;
}

Optic::Optic() {

}

void Optic::setWidht(float aWidht) {
	widht = aWidht;
}
float Optic::getWidht() {
	return widht;
}

void Optic::setDioptre(float aDioptre) {
	dioptre = aDioptre;
}
float Optic::getDioptre() {
	return dioptre;
}

void Optic::setType(string aType) {
	type = aType;
}
string Optic::getType() {
	return type;
}

void Optic::setMaterial(string aMaterial) {
	material = aMaterial;
}
string Optic::getMaterial() {
	return material;
}

void Optic::setPrice(float aPrice) {
	price = aPrice;
}
float Optic::getPrice() {
	return price;
}

istream& operator >> (istream& inoptic, Optic& obj) {
	inoptic >> obj.widht;
	inoptic >> obj.dioptre;
	inoptic >> obj.type;
	inoptic >> obj.material;
	inoptic >> obj.price;
	return inoptic;
}
ostream& operator <<(ostream& outoptic, const Optic& obj) {

	outoptic << obj.widht << "\n" << obj.dioptre << "\n" << obj.type
		<< "\n" << obj.material << "\n" << obj.price << endl;
	return outoptic;
}
