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

	vector<Memento<Water>*> WatersMemento_list;
	vector<Memento<Klient>*> KlientsMemento_list;
	vector<Memento<Order>*> OrdersMemento_list;

public:
	//Command();
	//~Command();

	//Water
	void PrintWaters();
	void AddWater();
	void DeleteWater();
	void FindWater();
	void UndoWaters();

	//Klient
	void PrintKlients();
	void AddKlient();
	void DeleteKlient();
	void FindKlient();
	void UndoKlients();

	//Orders
	void PrintOrders();
	void AddOrder();
	void DeleteOrder();
	void FindOrder();
	void UndoOrders();

	//Statistics
	void PrintIncome();
	void PrintWaterStats();
	void PrintKlientStats();
	

};

#endif // !COMMAND_H
