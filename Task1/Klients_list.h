#ifndef KLIENTS_LIST_H
#define KLIENTS_LIST_H

#include "Klient.h"
#include "List.h"
#include<vector>

class Klients_list : public List<Klient>{
public:
	Klients_list(int quantity = 0);

	void readData(string filename);
	void loadData(string filename) const;

	//void addObject(string name, string address, string number);

	void printData() const;
};

#endif // !KLIENTS_LIST_H
