#ifndef WATERS_LIST_H
#define WATERS_LIST_H

#include "Water.h"
#include "List.h"
#include<vector>

class Waters_list: public List<Water> {
public:
	Waters_list(int quantity = 0);
	
	void readData(string filename);
	void loadData(string filename) const;
	
	void addObject(string name, int volume, double price, bool artesian);
	
	void printData() const;
};

#endif // !WATERS_LIST_H

