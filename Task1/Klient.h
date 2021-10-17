#ifndef KLIENT_H
#define KLIENT_H

#include<string>
#include<iostream>
using namespace std;

class Klient {
private:
	int id;
	string name;
	string address;
	string phone_number;
public:
	static int id_count;
	
	Klient(int id=-1, string name="", string address="", string phone_number="");

	// getters
	int getId() const { return id; }
	string getName() const { return name; };
	string getAddress() const { return address; };
	string getNumber() const { return phone_number; };


	// setters
	void setName(string name);
	void setAddress(int address);
	void setPhoneNumber(double phone_number);

	string toString() const;

	ostream& operator<<(ostream& out) const;
	friend ostream& operator<<(ostream& out, const Klient& water);
};

#endif // !KLIENT_H

