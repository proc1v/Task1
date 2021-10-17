#include"Water.h"

int Water::id_count = 0;

Water::Water(int id, string name, int volume, double price, bool artesian)
	: id{id}, name{name}, volume{ volume }, price{ price }, artesian{ artesian } {
	id_count++;
}

void Water::setName(string name) { this->name = name; }
void Water::setVolume(int volume) { this->volume = volume; }
void Water::setPrice(double price) { this->price = price; }
void Water::setArtesian(bool artesian) { this->artesian = artesian; }

string Water::toString() const {
	return to_string(id) + ' ' + name + ' '
		+ to_string(volume) + ' ' + to_string(price) + ' '
		+ ((artesian) ? "true" : "false");
}

ostream& Water::operator<<(ostream& out) const{
	return out << this->toString();
}

ostream& operator<<(ostream& out, const Water& water) {
	return water << out;
}