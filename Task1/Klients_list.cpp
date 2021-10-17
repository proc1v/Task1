#include "Klients_list.h"
#include<fstream>
#include<iostream>

Klients_list::Klients_list(int quantity) : List(quantity) {}

void Klients_list::readData(string filename) {
	ifstream indata(filename);
	int id;
	string name;
	string address;
	string phone_number;

	indata >> quantity;

	for (int i = 0; i < quantity; i++) {
		indata >> id;
		indata.get();
		indata >> name;
		indata >> address;
		indata >> phone_number;
	
		db.push_back(Klient(id, name, address, phone_number));
	}
	
	Klient::id_count = this->getMaxId();

	indata.close();
}

void Klients_list::loadData(string filename) const {
	ofstream outdata(filename);

	outdata << quantity << endl;

	for (int i = 0; i < quantity; i++) {
		outdata << db[i].getId() << ' ' << db[i].getName() << ' '
			<< db[i].getAddress() << ' ' << db[i].getNumber() << endl;
	}

	outdata.close();
}

void Klients_list::addObject(string name, string address, string number) {
	quantity++;
	Klient::id_count++;
	db.push_back(Klient(Klient::id_count, name, address, number));
}

void Klients_list::printData() const {
	cout << "ID:  Name:  Address:  Phone number:\n";
	for (int i = 0; i < quantity; i++) {
		cout << db[i] << endl;
	}
}