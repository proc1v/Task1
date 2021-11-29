#pragma once
#include "List.h"


template<class T>
class Memento
{
private:
	friend class Klients_list;
	friend class Waters_list;
	friend class Orders_list;
	vector<T> _State;
	int _quantity;
public:
	Memento(vector<T>& State, int quantity) {
		/*vector<T> cpy(State);
		_State = cpy;*/
		_State = State;
		_quantity = quantity;
	}
};

