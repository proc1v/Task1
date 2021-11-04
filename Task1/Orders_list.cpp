#include "Orders_list.h"
#include<fstream>
#include<iostream>
using namespace std;

Orders_list::Orders_list(string filename) : List(filename) {
	readData();
}

Orders_list::~Orders_list() {
	loadData();
}

void Orders_list::readData() {
	bool prevSync = sync;
	sync = false;

	Waters_list water_db;
	Klients_list klient_db;
	
	ifstream indata(filename);
	int order_id;
	string date;
	int klient_id;
	int water_size = 0;
	int water_id = 0;
	
	vector<Water> waters;

	indata >> latestUpdate;
	indata >> quantity;

	for (int i = 0; i < quantity; i++) {
		indata >> order_id;
		indata.get();
		indata >> date;
		indata >> klient_id;
		indata >> water_size;
		
		for (int i = 0; i < water_size; i++) {
			indata >> water_id;
			waters.push_back(water_db.find(water_id));
		}
		db.push_back(Order(order_id, date, Klient(klient_db.find(klient_id)), waters));
		waters.clear();
	}
	Order::id_count = this->getMaxId()+1;

	indata.close();

	sync = prevSync;
}

void Orders_list::loadData() const {
	ofstream outdata(filename);

	outdata << latestUpdate << endl;
	outdata << quantity << endl;
	int number_of_waters;

	for (int i = 0; i < quantity; i++) {
		
		outdata << db[i].getId() << ' ' << db[i].getDate() << ' '
			<< db[i].getKlient().getId() << ' ';
		
		number_of_waters = db[i].getWater().size();

		outdata << number_of_waters;
		
		for (int j = 0; j < number_of_waters; j++) {
			outdata << ' ' << db[i].getWater()[j].getId();
		}
		outdata << endl;
	}
	outdata.close();
}

/*void Orders_list::addObject(string date, Klient klient, vector<Water> water) {
	quantity++;
	Order::id_count++;
	db.push_back(Order(Order::id_count, date, klient, water));
}*/

void Orders_list::printData() {
	syncRead();
	
	cout << "ID:  Date:\n";
	for (int i = 0; i < quantity; i++) {
		cout << db[i] << endl;
	}
}