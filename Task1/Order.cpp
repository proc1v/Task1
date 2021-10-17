#include"Order.h"

int Order::id_count = 0;

Order::Order(int id, string date, Klient klient, vector<Water> water)
	: id{ id }, date{ date }, klient{ klient }, water{ water } {
	id_count++;
}

void Order::setDate(string date) { this->date = date; }
void Order::setKlient(Klient klient) { this->klient = klient; }
void Order::setWater(vector<Water> water) { this->water = water; }

string Order::toString() const{
	string res = to_string(id) + " " + date + " Klient:\n"
		+ klient.toString() + "\nOrder list:\n";
	for (int i = 0; i < water.size(); i++) {
		res += water[i].toString() + "\n";
	}
	return res;
}

ostream& Order::operator<<(ostream& out) const{
	return out << this->toString();
}

ostream& operator<<(ostream& out, const Order& order) {
	return order << out;
}