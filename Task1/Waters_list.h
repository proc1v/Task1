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
	
	//void addObject(string name, int volume, double price, bool artesian);
	
	void printData() const;
};

#endif // !WATERS_LIST_H

