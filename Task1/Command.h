#ifndef COMMAND_H
#define COMMAND_H
#include "Klients_list.h"
#include "Orders_list.h"
#include "Waters_list.h"

class Command {
private:
	Klients_list klients_list;
	Waters_list waters_list;
	Orders_list orders_list;

	string klients_db;
	string waters_db;
	string orders_db;

public:
	Command(string klients_db = "klients_db.txt", 
		string waters_db = "waters_db.txt", 
		string orders_db = "orders_db.txt");
	~Command();

	//Water
	void PrintWaters() const;
	void AddWater();
	void DeleteWater();
	void FindWater();

	//Klient
	void PrintKlients() const;
	void AddKlient();
	void DeleteKlient();
	void FindKlient();

	//Orders
	void PrintOrders() const;
	void AddOrder();
	void DeleteOrder();
	void FindOrder();

	//Statistics
	void PrintIncome();
	void PrintWaterStats();
	void PrintKlientStats();
	

};

#endif // !COMMAND_H
