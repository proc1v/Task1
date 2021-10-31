#pragma once
#include<string>
#include<vector>
#include "Error.h"
using namespace std;

template<typename Object>
class List {
protected:
	vector<Object> db;
	int quantity;
public:
	List(int quantity = 0): quantity { quantity } {}

	int getQuantity() const { return quantity; }

	const vector<Object> getDB() const { return db; }
	
	void deleteObject(int id) {
		db.erase(db.begin() + find_pos(id));
		quantity--;
	}
	void deleteObject(string name) {
		db.erase(db.begin() + find_pos(name));
		quantity--;
	}

	void addObject(Object& obj) {
		quantity++;
		//Object::id_count++;
		db.push_back(obj);
	}

	virtual void printData() const = 0;

	int getMaxId() const {
		int max_id = 0;
		for (int i = 0; i < db.size(); ++i) {
			if (db[i].getId() > max_id) {
				max_id = db[i].getId();
			}
		}
		return max_id;
	}

	Object& find(int id) {
		for (int i = 0; i < quantity; i++) {
			if (db[i].getId() == id) {
				return db[i];
			}
		}
		throw Error(ErrorCode::WrongId);
	}
	Object& find(string name) {
		for (int i = 0; i < quantity; i++) {
			if (db[i].getName() == name) {
				return db[i];
			}
		}
		throw Error(ErrorCode::WrongName);
	}

	int find_pos(int id) {
		for (int i = 0; i < quantity; i++) {
			if (db[i].getId() == id) {
				return i;
			}
		}
		throw Error(ErrorCode::WrongId);
	}
	int find_pos(string name) {
		for (int i = 0; i < quantity; i++) {
			if (db[i].getName() == name) {
				return i;
			}
		}
		throw Error(ErrorCode::WrongName);
	}
};