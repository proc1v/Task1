#ifndef KLIENTS_LIST_H
#define KLIENTS_LIST_H

#include "Klient.h"
#include "List.h"
#include<vector>

class Klients_list : public List<Klient>{
public:
	Klients_list(string filename = "D:\\LNU\\practice 3rd sem\\Task1_v.0.1\\Task1\\klients_db.txt");
	~Klients_list();

	void readData();
	void loadData() const;

	//void addObject(string name, string address, string number);

	void printData();
};

#endif // !KLIENTS_LIST_H
