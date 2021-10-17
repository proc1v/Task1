#include "Klient.h"

int Klient::id_count = 0;

Klient::Klient(int id, string name, string address, string phone_number) 
	: id{id}, name {name}, address{ address }, phone_number{ phone_number }
{
	id_count++;
}

void Klient::setName(string name) { this->name = name; }
void Klient::setAddress(int address) { this->address = address; }
void Klient::setPhoneNumber(double phone_number) { this->phone_number = phone_number; }

string Klient::toString() const {
	return to_string(id) + ' ' + name + ' '
		+ address + ' ' + phone_number;
}

ostream& Klient::operator<<(ostream& out) const{
	return out << this->toString();
}

ostream& operator<<(ostream& out, const Klient& klient) {
	return klient << out;
}