#ifndef ORDERS_LIST_H
#define ORDERS_LIST_H

#include "List.h"
#include "Order.h"
#include "Klients_list.h"
#include "Waters_list.h"

class Orders_list : public List<Order> {
public:
	Orders_list(int quantity = 0);

	void readData(string filename, Waters_list& water_db, Klients_list& klient_db);
	void loadData(string filename) const;

	void addObject(string date, Klient klient, vector<Water> water);

	void printData() const;

};


#endif // !ORDERS_LIST_H

