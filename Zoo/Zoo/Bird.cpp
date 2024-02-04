#include "Bird.h"

int Bird::eat() const {
	return weight / 10 + numberOfEggs;
}

food Bird::getFood() const {
	return this->foodType;
}

std::string Bird::getRescueCity() const {
	return rescueCity;
}

int Bird::getNumberOfEggs() const {
	return numberOfEggs;
}

Bird::Bird(const char* _name, double weight, food foodType, std::string rescueCity, int numberOfEggs) : Animal(_name, weight, foodType), rescueCity(rescueCity), numberOfEggs(numberOfEggs) {}

Bird::Bird(const Bird& other) : Animal(other) {
	this->rescueCity = other.rescueCity;
	this->numberOfEggs = other.numberOfEggs;
}

Bird& Bird::operator=(const Bird& other) {
	if (this != &other)
	{
		Animal::operator=(other);
		this->rescueCity = other.rescueCity;
		this->numberOfEggs = other.numberOfEggs;
	}
	return *this;
}