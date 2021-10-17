#ifndef WATER_H
#define WATER_H

#include<string>
#include<iostream>
using namespace std;

class Water{
private:
	int id;
	string name;
	int volume;
	double price;
	bool artesian;

public:
	static int id_count;

	Water(int id, string name = "", int volume = 0, double price = 0, bool artesian = false);
	
	// getters
	int getId() const { return id; }
	string getName() const { return name; };
	int getVolume() const { return volume; };
	double getPrice() const { return price; };
	bool getArtesian() const { return artesian; }
	

	// setters
	void setName(string name);
	void setVolume(int volume);
	void setPrice(double price);
	void setArtesian(bool artesian);
	
	string toString() const;
	
	ostream& operator<<(ostream& out) const;
	friend ostream& operator<<(ostream& out, const Water& water);
};

#endif // !WATER_H