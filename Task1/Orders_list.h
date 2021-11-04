#ifndef ORDERS_LIST_H
#define ORDERS_LIST_H

#include "List.h"
#include "Order.h"
#include "Klients_list.h"
#include "Waters_list.h"

class Orders_list : public List<Order> {
public:
	Orders_list(string filename = "D:\\LNU\\practice 3rd sem\\Task1_v.0.1\\Task1\\orders_db.txt");
	~Orders_list();


	//void readData(Waters_list& water_db, Klients_list& klient_db);
	void readData();
	void loadData() const;

	//void addObject(string date, Klient klient, vector<Water> water);

	void printData() const;

};


#endif // !ORDERS_LIST_H

