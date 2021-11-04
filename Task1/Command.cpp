#include"Command.h"
#include<iostream>
using namespace std;

/*Command::Command() 
{
	klients_list.readData();
	waters_list.readData();
	orders_list.readData();
}
Command::~Command() {
	klients_list.loadData();
	waters_list.loadData();
	orders_list.loadData();
}*/


void Command::PrintWaters(){
	waters_list.printData();
}
void Command::AddWater() {
	string name;
	int volume;
	double price;
	bool artesian;
	
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter volume: ";
	cin >> volume;
	cout << "Enter price: ";
	cin >> price;
	cout << "Is artesian? (1 - yes, 0 - no): ";
	cin >> artesian;
	
	Water object(Water::id_count, name, volume, price, artesian);

	waters_list.addObject(object);
}
void Command::DeleteWater() {
	string answer;
	int id;
	cout << "Delete by id or name? ";
	cin >> answer;
	if (answer == "id") {
		cout << "Enter ID: ";
		cin >> id;
		waters_list.deleteObject(id);
	}
	else if (answer == "name") {
		cout << "Enter name: ";
		cin >> answer;
		waters_list.deleteObject(answer);
	}
	else {
		throw Error(ErrorCode::WrongCommand);
	}
}
void Command::FindWater() {
	string answer;
	int id;
	
	cout << "Find by id or name?";
	cin >> answer;
	if (answer == "id") {
		cout << "Enter ID: ";
		cin >> id;
		cout << waters_list.find(id).toString();
	}
	else if (answer == "name") {
		cout << "Enter name: ";
		cin >> answer;
		cout << waters_list.find(answer).toString();
	}
	else {
		throw Error(ErrorCode::WrongCommand);
	}
}


void Command::PrintKlients(){
	klients_list.printData();
}
void Command::AddKlient() {
	string name;
	string address;
	string phone_number;

	cout << "Enter name: ";
	cin >> name;
	cout << "Enter address: ";
	cin >> address;
	cout << "Enter pnone number: ";
	cin >> phone_number;
	
	Klient klient(Klient::id_count, name, address, phone_number);

	klients_list.addObject(klient);
}
void Command::DeleteKlient() {
	string answer;
	int id;
	cout << "Delete by id or name? ";
	cin >> answer;
	if (answer == "id") {
		cout << "Enter ID: ";
		cin >> id;
		klients_list.deleteObject(id);
	}
	else if (answer == "name") {
		cout << "Enter name: ";
		cin >> answer;
		klients_list.deleteObject(answer);
	}
	else {
		throw Error(ErrorCode::WrongCommand);
	}
}
void Command::FindKlient() {
	string answer;
	int id;

	cout << "Find by id or name?";
	cin >> answer;
	if (answer == "id") {
		cout << "Enter ID: ";
		cin >> id;
		cout << klients_list.find(id).toString();
	}
	else if (answer == "name") {
		cout << klients_list.find(answer).toString();
	}
	else {
		throw Error(ErrorCode::WrongCommand);
	}
}


void Command::PrintOrders(){
	orders_list.printData();
}
void Command::AddOrder() {
	string date;
	Klient klient;
	string klient_answer;
	string water_answer;
	int water_quantity;
	vector<Water> water_list;
	int water_id;
	int klient_id;

	cout << "Enter date: ";
	cin >> date;
	cout << "Find klient by id or name?";
	cin >> klient_answer;

	if (klient_answer == "id") {
		cout << "Enter ID: ";
		cin >> klient_id;

		try
		{
			klient = Klient(this->klients_list.find(klient_id));
		}
		catch (Error& error)
		{
			cout << error.ToString() << endl;
			cout << "Want to create new Klient? (yes/no): ";
			cin >> klient_answer;
			if (klient_answer == "yes") {
				AddKlient();
				return;
			}
		}
	}
	else if (klient_answer == "name") {
		cout << "Enter name: ";
		cin >> klient_answer;
		
		try
		{
			klient = Klient(this->klients_list.find(klient_answer));
		}
		catch (Error& error)
		{
			cout << error.ToString() << endl;
			cout << "Want to create new Klient? (yes/no): ";
			cin >> klient_answer;
			if (klient_answer == "yes") {
				AddKlient();
			}
			return;
		}
	}
	else {
		throw Error(ErrorCode::WrongCommand);
	}

	cout << "Enter quantity of waters: ";
	cin >> water_quantity;

	for (int i = 0; i < water_quantity; i++) {
		cout << i + 1 << ") Enter water name or id: ";
		cin >> water_answer;
		
		try {
			if (isdigit(water_answer[0])) {
				water_id = stoi(water_answer);
				water_list.push_back(this->waters_list.find(water_id));
			}
			else {
				water_list.push_back(this->waters_list.find(water_answer));
			}
		}
		catch (Error& error) {
			cout << error.ToString() << endl;
			cout << "Want to create new Water? (yes/no): ";
			cin >> klient_answer;
			if (klient_answer == "yes") {
				AddWater();
			}
			return;
		}
	}

	Order order(Order::id_count, date, klient, water_list);

	orders_list.addObject(order);
}
void Command::DeleteOrder() {
	string answer;
	int id;
	
	cout << "Enter ID: ";
	cin >> id;
	orders_list.deleteObject(id);
}
void Command::FindOrder() {
	string answer;
	int id;
	
	cout << "Enter ID: ";
	cin >> id;
	cout << orders_list.find(id).toString();
}


void Command::PrintIncome() {
	double income = 0;

	vector<Order> orders = orders_list.getDB();
	vector<Water> water_list;

	for (int i = 0; i < orders_list.getQuantity(); i++) {
		water_list = orders[i].getWater();
		for (int j = 0; j < water_list.size(); j++) {
			income += water_list[j].getPrice();
		}
	}
	cout << "Total income: " << income << endl;
}
void Command::PrintWaterStats() {
	
	vector<Water> waters = waters_list.getDB();
	vector<Order> orders = orders_list.getDB();
	vector<int> count_of_water(waters_list.getQuantity());
	vector<Water> water_list;;

	for (int i = 0; i < orders_list.getQuantity(); i++) {
		water_list = orders[i].getWater();
		for (int j = 0; j < water_list.size(); j++) {
			for (int k = 0; k < waters.size(); k++) {
				if (waters[k].getId() == water_list[j].getId()) {
					count_of_water[waters_list.find_pos(waters[k].getId())]++;
					break;
				}
			}
		}
	}
	cout << "Water:    Count:\n";
	for (int i = 0; i < waters.size(); i++) {
		cout << waters[i].toString() << " : " << count_of_water[i] << endl;
	}
}
void Command::PrintKlientStats() {
	vector<Order> orders = orders_list.getDB();
	vector<Klient> klients = klients_list.getDB();
	vector<int> count_of_klients(klients_list.getQuantity());
	Klient klient;

	for (int i = 0; i < orders_list.getQuantity(); i++) {
		klient = orders[i].getKlient();
		for (int j = 0; j < klients.size(); j++) {
			if (klients[j].getId() == klient.getId()) {
				count_of_klients[klients_list.find_pos(klient.getId())]++;
			}
		}
	}
	cout << "Klient:    Count:\n";
	for (int i = 0; i < klients.size(); i++) {
		cout << klients[i].toString() << " : " << count_of_klients[i] << endl;
	}
}