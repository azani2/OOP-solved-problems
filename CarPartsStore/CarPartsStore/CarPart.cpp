#include "CarPart.h"

unsigned CarPart::count = 0;

void CarPart::displayBase() const {
	std::cout << name << ", " << manufacturer << ", " << year << ", " << id;
}

unsigned CarPart::getCount() {
	return count;
}

CarPart::CarPart(std::string name, std::string manufacturer, unsigned year) : name(name), manufacturer(manufacturer), year(year) {
	id = count++;
}