#include "Piston.h"

void Piston::display() const {
	displayBase();
	std::cout << ", " << diameter << "mm, " << range << "mm\n";
}

CarPart* Piston::clone() const {
	return new Piston(*this);
}

Piston::Piston(std::string name, std::string manufacturer, unsigned year, double diameter, double range) : CarPart(name, manufacturer, year), diameter(diameter), range(range) {}