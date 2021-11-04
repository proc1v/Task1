#pragma once
#include<string>
#include<vector>
#include "Error.h"
#include<fstream>
using namespace std;

template<typename Object>
class List {
protected:
	vector<Object> db;
	int quantity;
	string filename = "";
	
	int latestUpdate;
	bool sync = true;

	int getFileUpdate() {
		ifstream indata(filename);
		int update;
		indata >> update;

		indata.close();
		return update;
	}

	void syncWrite() {
		if (sync) {
			latestUpdate++;
			loadData();
		}
	}

	void syncRead() {
		int currUpdate = getFileUpdate();
		if (latestUpdate != currUpdate && sync) {
			db.clear();
			
			readData();
			latestUpdate = currUpdate;
		}
	}

public:
	List(string filename = "") : quantity{ 0 }, filename{filename} {
		//readData();
	}
	~List() {
		//loadData();
	}

	int getQuantity() const { return quantity; }

	const vector<Object> getDB() const { return db; }
	
	void deleteObject(int id) {
		db.erase(db.begin() + find_pos(id));
		quantity--;

		syncWrite();
	}
	void deleteObject(string name) {
		db.erase(db.begin() + find_pos(name));
		quantity--;

		syncWrite();
	}

	void addObject(Object& obj) {
		quantity++;
		//Object::id_count++;
		db.push_back(obj);

		syncWrite();
	}

	virtual void printData() = 0;
	virtual void readData() = 0;
	virtual void loadData() const = 0;

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
		syncRead();
		
		for (int i = 0; i < quantity; i++) {
			if (db[i].getId() == id) {
				return db[i];
			}
		}
		throw Error(ErrorCode::WrongId);
	}
	Object& find(string name) {
		syncRead();
		
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