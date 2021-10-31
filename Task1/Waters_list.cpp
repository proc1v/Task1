#include "Waters_list.h"
#include<fstream>
#include<iostream>

Waters_list::Waters_list(int quantity) : List(quantity) {}

void Waters_list::readData(string filename) {
	ifstream indata(filename);
	int id;
	string name;
	int volume;
	double price;
	bool artesian;

	indata >> quantity;

	for (int i = 0; i < quantity; i++) {
		indata >> id;
		indata.get();
		indata >> name;
		indata >> volume;
		indata >> price;
		indata >> artesian;

		db.push_back(Water(id, name, volume, price, artesian));
	}
	Water::id_count = this->getMaxId()+1;

	indata.close();
}

void Waters_list::loadData(string filename) const{
	ofstream outdata(filename);

	outdata << quantity << endl;

	for (int i = 0; i < quantity; i++) {
		outdata << db[i].getId() << ' ' << db[i].getName() << ' '
			<< db[i].getVolume() << ' ' << db[i].getPrice() << ' '
			<< db[i].getArtesian() << endl;
	}

	outdata.close();
}

/*void Waters_list::addObject(string name, int volume, double price, bool artesian) {
	quantity++;
	Water::id_count++;
	db.push_back(Water(Water::id_count, name, volume, price, artesian));
}*/

void Waters_list::printData() const {
	cout << "ID:  Name:  Volume:  Price for 1l: Artesian:\n";
	for (int i = 0; i < quantity; i++) {
		cout << db[i] << endl;
	}
}