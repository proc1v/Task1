#ifndef WATERS_LIST_H
#define WATERS_LIST_H

#include "Water.h"
#include "List.h"
#include<vector>

class Waters_list: public List<Water> {
public:
	Waters_list(string filename = "D:\\LNU\\practice 3rd sem\\Task1_v.0.1\\Task1\\waters_db.txt");
	~Waters_list();
	
	void readData();
	void loadData() const;

	Memento<Water>* createMemento()
	{
		return new Memento<Water>(db, quantity);
	}
	void reinstateMemento(Memento<Water>* mem)
	{
		db = mem->_State;
		quantity = mem->_quantity;
	}
	
	//void addObject(string name, int volume, double price, bool artesian);
	
	void printData();
};

#endif // !WATERS_LIST_H

