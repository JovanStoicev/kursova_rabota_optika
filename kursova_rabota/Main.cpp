#include <iostream>
#include <string>
#include <limits>
#include <vector> 
#include <fstream>
#include "Provider.h"
#include "Orderer.h"
#include "Optic.h"

using namespace std;

vector <Provider> readProviderFromFile() {

	vector <Provider> listOfProvider;
	ifstream providerFile;
	providerFile.open("Providersi.txt");
	string name,
		number,
		bulstat,
		location;
	while (!providerFile.eof()) {

		Provider newProvider;
		providerFile >> newProvider;
		if (!(newProvider.getBulstat() == "***********" || newProvider.getNumber() == "***********")) {
			listOfProvider.push_back(newProvider);
		}

	}

	listOfProvider.pop_back();
	providerFile.close();
	return listOfProvider;
}

vector <Optic> readOpticFromProviderFile(string fileName) {

	vector <Optic> listOfOptic;
	ifstream providerOpticFile;
	providerOpticFile.open(fileName);
	string name,
		number,
		bulstat,
		location;
	while (!providerOpticFile.eof()) {
		Optic newOptic;
		providerOpticFile >> newOptic;
		listOfOptic.push_back(newOptic);
	}

	listOfOptic.pop_back();
	providerOpticFile.close();
	return listOfOptic;
}

void readAllOrders() {
	ifstream ordersFile;
	vector <string> allOrders;
	ordersFile.open("Ordered.txt");

	while (!ordersFile.eof()) {
		for (string line; getline(ordersFile, line); )
		{
			allOrders.push_back(line);
		}
	}
	for (int i = 0; i < allOrders.size(); i++) {
		cout << allOrders[i] << endl;
	}
}

Provider createProvider() {

	string name;
	string number;
	string bulstat;
	string location;
	string newProviderFileName;
	int flag, flagProvider = 0;
	Provider provider;

	ofstream newProviderFile;
	ofstream providerFile;
	providerFile.open("Providersi.txt", ios_base::app);
	if (providerFile.fail()) {
		cout << "File can not be opened!" << endl;
	}
	else {

		cin.ignore(numeric_limits<streamsize>::max(), '\n');//fflush() cisti memorijutu da se ne baguje tekstat

		cout << "input provider name: ";
		getline(cin, name);
		cout << "input provider number: ";
		getline(cin, number);
		for (int i = 0; i < number.length(); i++) {
			flag = 0;
			if (number[i] >= '0' && number[i] <= '9' || number[i] == ' ') {
				flag = 0;
				continue;
			}
			else {
				cout << "Wrong number!" << endl;
				flag = 1;
				number = "***********";
			}
			if (flag == 1) {
				break;
			}
		}
		cout << "input provider bulstat: ";
		getline(cin, bulstat);
		for (int i = 0; i < bulstat.length(); i++) {
			flag = 0;
			if (bulstat[i] >= '0' && bulstat[i] <= '9') {
				flag = 0;
				continue;
			}
			else {
				cout << "Wrong bulstat!" << endl;
				flag = 1;
				bulstat = "***********";
			}
			if (flag == 1) {
				break;
			}
		}
		cout << "input provider location: ";
		getline(cin, location);


		Provider provider(name, number, bulstat, location);
		for (Provider tempProvider : readProviderFromFile()) {
			if (!(tempProvider.getBulstat() == provider.getBulstat()))
			{
				continue;
			}
			else {
				flagProvider = 1;
				cout << "This provider already exist." << endl;
				break;
			}
		}
		if (flagProvider == 0) {
			providerFile << provider;
			newProviderFileName = provider.getName() + provider.getBulstat() + ".txt";
			newProviderFile.open(newProviderFileName);

			cout << "provider name: " << provider.getName() << "\t" << "provider number: " << provider.getNumber() << "\t" <<
				"provider bulstat: " << provider.getBulstat() << "\t" << "provider location: " << provider.getLocation() << endl;
			newProviderFile.close();
		}

		providerFile.close();

	}
	return provider;
}

Optic createOptic() {


	float widht, dioptre, price;
	string type, material;


	cin.ignore(numeric_limits<streamsize>::max(), '\n');//fflush() cisti memorijutu da se ne baguje tekstat
	cout << "please enter optic widht: ";
	cin >> widht;
	cout << "please enter optic dioptre: ";
	cin >> dioptre;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');//fflush() cisti memorijutu da se ne baguje tekstat
	cout << "please enter optic type: ";
	getline(cin, type);
	cout << "please enter optic material: ";
	getline(cin, material);
	cout << "please enter optic price: ";
	cin >> price;



	Optic optika(widht, dioptre, type, material, price);

	cout << "\nOptic widht:" << optika.getWidht() << endl;
	cout << "Optic dioptre: " << optika.getDioptre() << endl;
	cout << "Optic type: " << optika.getType() << endl;
	cout << "Optic material: " << optika.getMaterial() << endl;
	cout << "Optic price: " << optika.getPrice() << endl;

	return optika;
}

Orderer createOrderer() {
	string firstName;
	string lastName;
	string city;
	string address;
	string phone;
	Orderer orderer;
	int flag = 0;

	ofstream ordererFile;
	ordererFile.open("Orderers.txt", ios_base::app);
	if (ordererFile.fail()) {
		cout << "File can not be opened!" << endl;
	}
	else {

		cin.ignore(numeric_limits<streamsize>::max(), '\n');//fflush() cisti memorijutu da se ne baguje tekstat

		cout << "input orderer first name: ";
		getline(cin, firstName);
		cout << "input orderer last name: ";
		getline(cin, lastName);
		cout << "input orderer city: ";
		getline(cin, city);
		cout << "input orderer address: ";
		getline(cin, address);
		cout << "input orderer phone number: ";
		getline(cin, phone);
		for (int i = 0; i < phone.length(); i++) {
			flag = 0;
			if (phone[i] >= '0' && phone[i] <= '9' || phone[i] == ' ') {
				flag = 0;
				continue;
			}
			else {
				cout << "Wrong number!" << endl;
				flag = 1;
				phone = "***********";
			}
			if (flag == 1) {
				break;
			}
		}

		Orderer orderer(firstName, lastName, city, address, phone);
		if (flag == 0) {
			ordererFile << orderer;
		}
		return orderer;
		ordererFile.close();
	}
	return orderer;
}


int main() {

	int chose;
	string selectProviderName, selectProviderBulstat;
	vector <Provider> listOfProvider;
	vector <Provider> list_of_providers;
	Provider newProvider;
	Optic newOptic;
	ofstream orderedFile;
	ifstream providerNameFile;

	while (1) {
		cout << "\n";
		cout << "1. Create provider" << endl;
		cout << "2. Chose provider and create optic" << endl;
		cout << "3. Make an order" << endl;
		cout << "4. See all providers" << endl;
		cout << "5. See all orders" << endl;
		cout << "0. Close application" << endl;
		cout << "\nYour choise: ";

		cin >> chose;
		if (chose == 1) {

			newProvider = createProvider();
			listOfProvider.push_back(newProvider);
		}
		if (chose == 2) {
			readProviderFromFile();

			if (!readProviderFromFile().empty()) {
				cout << "Select one of avaible provider, plesase: \n" << endl;
				for (Provider provider : readProviderFromFile()) {
					cout << "Provider name: " << provider.getName() << "\tProvider number: " << provider.getNumber()
						<< "\tProvider bulstat: " << provider.getBulstat() << "\tProvider location: "
						<< provider.getLocation() << endl;
				}
				cout << "Input name of provider you want: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//fflush() cisti memorijutu da se ne baguje tekstat
				getline(cin, selectProviderName);
				cout << "Input bulstat of provider you want: ";
				getline(cin, selectProviderBulstat);

				for (int i = 0; i < readProviderFromFile().size(); i++) {
					if ((selectProviderName == readProviderFromFile()[i].getName()))
					{
						
						if (selectProviderBulstat == readProviderFromFile()[i].getBulstat()) {
							cout << "You select this provider to oreder you optic: " <<
								readProviderFromFile()[i].getName() << " " << readProviderFromFile()[i].getNumber() << " " <<
								readProviderFromFile()[i].getBulstat() << " " << readProviderFromFile()[i].getLocation() << endl;
							
							string providerFileName = readProviderFromFile()[i].getName() +
								readProviderFromFile()[i].getBulstat() + ".txt";
							ofstream providerFile;
							providerFile.open(providerFileName, ios_base::app);
							newOptic = createOptic();
							providerFile << newOptic;
						}
					}
				}
			}
			else
			{
				cout << " There is no Provider, u can't order optic";
			}
		}
		if (chose == 3) {
			string ordererFirstName, ordererLastName, ordererCity, ordererAddress, ordererPhone;
			string selectOpticWidht, selectOpticDioptre, selectOpticType, selectOpticMaterial, selectOpticPrice;
			string confirmShop;
			Orderer newOrderer;
			float finalPrice = 0;
			float floatPrice, floatWidht, floatDioptre;
			readProviderFromFile();

			if (!readProviderFromFile().empty()) {

				cout << "Select one of avaible provider, plesase: \n" << endl;
				for (Provider provider : readProviderFromFile()) {
					cout << "Provider name: " << provider.getName() << "\tProvider number: " << provider.getNumber()
						<< "\tProvider bulstat: " << provider.getBulstat() << "\tProvider location: "
						<< provider.getLocation() << endl;
				}
				cout << "Input name of provider you want: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//fflush() cisti memorijutu da se ne baguje tekstat
				getline(cin, selectProviderName);
				cout << "Input bulstat of provider you want: ";
				getline(cin, selectProviderBulstat);

				for (int i = 0; i < readProviderFromFile().size(); i++) {

					if ((selectProviderName == readProviderFromFile()[i].getName()))
					{
						if (selectProviderBulstat == readProviderFromFile()[i].getBulstat()) {
							string stringForFileName;
							stringForFileName = readProviderFromFile()[i].getName() +
								readProviderFromFile()[i].getBulstat() + ".txt";
							vector<Optic> tempOptic = readOpticFromProviderFile(stringForFileName);
							cout << "You select this provider to oreder you optic: " <<
								readProviderFromFile()[i].getName() << " " << readProviderFromFile()[i].getNumber() << " " <<
								readProviderFromFile()[i].getBulstat() << " " << readProviderFromFile()[i].getLocation() << "\n" << endl;
						
							Orderer newOrderer;
							newOrderer = createOrderer();
							vector <Optic> opticBuyList;
							while (1) 
							{
								for (Optic optic : tempOptic) {
									cout << "Optic widht: " << optic.getWidht() << "\tOptic diptre: " << optic.getDioptre() <<
										"\tOptic type: " << optic.getType() << "\tOptic material: " << optic.getMaterial() <<
										"\tOptic price: " << optic.getPrice() << endl;
								}
								while (!(confirmShop == "Y" || confirmShop == "y" ||
									confirmShop == "N" || confirmShop == "n")) {

									cout << "Do you wanna to continue with shop? [Y/N]: ";
									getline(cin, confirmShop);
								}
								if (confirmShop == "N" || confirmShop == "n") {
									if (finalPrice != 0) {
										cout << "\nYou order this items: " << "\n" << "**************************"<<endl;
										for (Optic opticlist : opticBuyList) {
											
											cout << "Optic: widht: "<<opticlist.getWidht()<<"\n"
												<<"Optic: dioptre: " << opticlist.getDioptre() << "\n"
												<<"Optic: type: " << opticlist.getType() << "\n"
												<<"Optic: material: " << opticlist.getMaterial() << "\n"
												<<"Optic: price: " << opticlist.getPrice() << "\n"
												<<"-------------------------\n";
											
										}
										cout << "On name: " << newOrderer.getFirstName() << " " << newOrderer.getLastName()<<endl;
										cout << "When stuff is delivered you need to pay: " << finalPrice << "BGN."<<endl;
									}
									break;
								}
								if (confirmShop == "Y" || confirmShop == "y") {
									cout << "\n" << "Select which optic you want to buy." << endl;

									cout << "Input widht: ";
									cin >> floatWidht;
									cout << "Input dioptre: ";
									cin >> floatDioptre;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');//fflush() cisti memorijutu da se ne baguje tekstat
									cout << "Input type: ";
									getline(cin, selectOpticType);
									cout << "Input material: ";
									getline(cin, selectOpticMaterial);

									for (int i = 0; i < tempOptic.size(); i++) {

										if (floatWidht == tempOptic[i].getWidht())
										{
											if (floatDioptre == tempOptic[i].getDioptre())
											{
												if (selectOpticType == tempOptic[i].getType())
												{
													if (selectOpticMaterial == tempOptic[i].getMaterial()) {

														floatPrice = tempOptic[i].getPrice();
														finalPrice += floatPrice;
														opticBuyList.push_back(tempOptic[i]);

														orderedFile.open("Ordered.txt", ios_base::app);
														orderedFile << "Provider name: " << readProviderFromFile()[i].getName() << "\n" <<
															"Provider number: " << readProviderFromFile()[i].getNumber() << "\n" <<
															"Provider bulstat: " << readProviderFromFile()[i].getBulstat() << "\n" <<
															"Provider location: " << readProviderFromFile()[i].getLocation() << "\n" <<
															"Optic widht: " << floatWidht << "\n" << "Optic dioptre: " << floatDioptre << "\n" <<
															"Optic type: " << selectOpticType << "\n" << "Optic material: " << selectOpticMaterial << "\n" <<
															"Orderer full name: " << newOrderer.getFirstName() << " " << newOrderer.getLastName() << "\n" <<
															"Orderer city: " << newOrderer.getCity() << "\n" <<
															"Orderer adress: " << newOrderer.getAddress() << "\n" << "Orderer phone number: " << newOrderer.getPhone()<<"\n\n";
														orderedFile.close();
														cout << "You successfully add item to your basket\n";
														confirmShop = "";
													}
												}
											}
										}
									}
								}

							}

						}
						
					}
					
				}
			}
			else
			{
				cout << " There is no Provider, u can't order optic";
			}
		}
		if (chose == 4) {
			readProviderFromFile();
			for (Provider provider : readProviderFromFile()) {
				cout << "Provider name: " << provider.getName() << "\tProvider number: " << provider.getNumber()
					<< "\tProvider bulstat: " << provider.getBulstat() << "\tProvider location: "
					<< provider.getLocation() << endl;
			}
		}
		if (chose == 5) {
			readAllOrders();
		}
		if (chose == 0) {
			break;
		}
	}
}