#include "Tire.h"

void Tire::display() const {
	displayBase();
	std::cout << ", " << width << "mm, " << profile << ", " << diameter << "in\n";
}

CarPart* Tire::clone() const {
	return new Tire(*this);
}

Tire::Tire(std::string name, std::string manufacturer, unsigned year, unsigned width, int profile, unsigned diameter) : CarPart(name, manufacturer, year), width(width), profile(profile), diameter(diameter) {}