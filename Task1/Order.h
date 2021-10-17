#ifndef ORDER_H
#define ORDER_H

#include<string>
#include<vector>
#include<iostream>
#include"Klient.h"
#include"Water.h"
using namespace std;

class Order {
private:
	int id;
	string date;
	Klient klient;
	vector<Water> water;
public:
	static int id_count;

	Order(int id, string date, Klient klient, vector<Water> water);

	//getters
	string getName() const { return to_string(id); }
	int getId() const { return id; }
	string getDate() const { return date; };
	Klient getKlient() const { return klient; };
	vector<Water> getWater() const { return water; };

	// setters
	void setDate(string name);
	void setKlient(Klient klient);
	void setWater(vector<Water> water);

	string toString() const;

	ostream& operator<<(ostream& out) const;
	friend ostream& operator<<(ostream& out, const Order& order);
};

#endif	