#include "Animal.h"

unsigned Animal::animalsCreated = 0;

void Animal::copy(const Animal& other) {
	name = new char[strlen(other.name)];
	strcpy(name, other.name);
	weight = other.weight;
	foodType = other.foodType;
}

void Animal::free() {
	delete[] name;
}

unsigned Animal::getAnimalsCount() {
	return animalsCreated;
}

char* Animal::getName() const {
	return name;
}

double Animal::getWeight() const {
	return weight;
}

Animal::Animal(const char* _name, double weight, food foodType) : weight(weight), foodType(foodType) {
	animalsCreated++;
	name = new char[strlen(_name)];
	strcpy(name, _name);
}

Animal::Animal(const Animal& other) {
	copy(other);
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Animal::~Animal() {
	free();
}

